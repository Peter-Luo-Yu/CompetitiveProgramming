/*Author: Peter Yu
   It is ok to share my code anonymously for educational purposes */

//#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#define space cerr << "----------" << endl;
#else
#define print(...) 6
#define space 7
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p);
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr> ostream& operator << (ostream &os, const C &c);

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T, typename enable_if<!is_same<C, string>::value>::type*> ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}

template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}


#define ll long long
#define ld long double
#define endl "\n"

struct PersistentSegTree {
    struct Node {
        int lc = 0, rc = 0;
        ll sum = 0;
    };

    ll n;
    vector<Node> Nodes;
    vector<int> roots;

    void init(ll x, int updates) {
        n = x;
        Nodes.clear(); Nodes.reserve(1 + updates * 20);
        Nodes.push_back(Node());                       
        roots.assign(1, 0);                           
    }

    int newNode(int from) { 
        Nodes.push_back(Nodes[from]); 
        return Nodes.size() - 1; 
    }

    
    int update(int prev, ll l, ll r, ll pos, ll val) {
        int cur = newNode(prev);                      
        Nodes[cur].sum += val;
        if (l < r) {
            ll mid = (l + r) / 2;
            if (pos <= mid) { 
                int c = update(Nodes[prev].lc, l, mid, pos, val);    
                Nodes[cur].lc = c;
            }
            else { 
                int c = update(Nodes[prev].rc, mid + 1, r, pos, val); 
                Nodes[cur].rc = c; 
            }
        }
        return cur;
    }

   
    int update(int ver, ll pos, ll val) {
        int r = update(roots[ver], 0, n - 1, pos, val);
        roots.push_back(r);
        return roots.size() - 1;
    }

    ll sum(int v, ll l, ll r, ll ql, ll qr) {
        if (v == 0 || qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return Nodes[v].sum;
        ll mid = (l + r) / 2;
        return sum(Nodes[v].lc, l, mid, ql, qr) + sum(Nodes[v].rc, mid + 1, r, ql, qr);
    }

    ll sum(int ver, ll ql, ll qr) {
        return sum(roots[ver], 0, n - 1, ql, qr); 
    }
    
    ll findk(int ver, ll k) {
        int v = roots[ver]; 
        ll l = 0, r = n - 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll leftSum = Nodes[Nodes[v].lc].sum;
            if (leftSum > k) { \
                v = Nodes[v].lc; 
                r = mid;
            }
            else { 
                k -= leftSum;
                v = Nodes[v].rc;
                l = mid + 1;
            }
        }
        return l;
    }

    // finds the position of the element that has exactly k elements smaller than it to the left
    ll findk(int vr, int vl, ll k) {
        int a = roots[vr], b = roots[vl]; 
        ll l = 0, r = n - 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll leftSum = Nodes[Nodes[a].lc].sum - Nodes[Nodes[b].lc].sum;
            if (leftSum > k) {
                a = Nodes[a].lc; 
                b = Nodes[b].lc;
                r = mid; 
            }
            else { 
                k -= leftSum; 
                a = Nodes[a].rc; 
                b = Nodes[b].rc;
                l = mid + 1;
            }
        }
        return l;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, k; cin >> n >> k;
    vector<ll> arr (n);

    vector<pair<ll, ll>> temp (n); 
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = {arr[i], i};  // coordinate - weight
    }

    sort (temp.begin(), temp.end());

    vector<ll> cord (n), weight(n), order(n), rankOfWeight(n + 1); // based on rank = sorted position
    for (int i = 0; i < n; i++) {
        cord[i] = temp[i].first;
        weight[i] = temp[i].second + 1;
        order[temp[i].second] = i; // orig index -> rank
        rankOfWeight[weight[i]] = i;
    }
    
    // This guy finds the threshold: T = kth largest weight in [l, r]
    PersistentSegTree Psegtree;
    Psegtree.init(n + 1, n);
    for (int i = 0; i < n; i++) {
        Psegtree.update(i, weight[i], 1); // version i, has everything up to weight i
    }

    // visited 2d array for all states (scale, pos)
    // Note: position 34 is reserved for the starting state.
    vector<vector<bool>> vis (35, vector<bool> (n + 1, false));

    vector<pair<int, int>> cur, nxt; // (scale, pos)
    vis[1][n] = true;
    cur.push_back({1, n});

    // edge case, 0 might also be a view point
    int idx0 = lower_bound(cord.begin(), cord.end(), 0LL) - cord.begin();
    if (idx0 < n && cord[idx0] == 0) {
        vis[1][idx0] = 1;
        cur.push_back({1, idx0});
    }

    vector<ll> ans (n, -1);
    ll d = 0; // dist from start

    while (!cur.empty()) { // the BFS
        for (auto [j, idx] : cur) {
            ll X;   // center
            if (idx == n) X = 0;    // pos n = 34 reserved for starting state which is 0
            else X = cord[idx];

            ll R; // radius
            if (j == 0) R = 0;
            else R = (1LL << (j - 1)); // remember scale is 2 ^ (j - 1)

            // Step 1 : Recenter

            int l = lower_bound(cord.begin(), cord.end(), X - R) - cord.begin();
            int r = upper_bound(cord.begin(), cord.end(), X + R) - cord.begin() - 1;
            
            ll numnodes = r - l + 1;
            if (numnodes > 0) {
                // how many viewpoints visible in current window
                ll amt = min(numnodes, k);

                // you want the weight of element with amt - 1 elements bigger than it
                // so we have (total - amt | goal node | amt - 1)
                // this is equivalent to having total - amt nodes to the left of it
                ll Threshold = Psegtree.findk(r + 1, l, numnodes - amt);

                // update the current state
                if (idx < n && ans[idx] < 0 && weight[idx] >= Threshold) {
                    ans[idx] = d;
                }


                // BFS enqueue the neighbors
                for (int i = 0; i < amt; i++) {
                    ll w = Psegtree.findk(r + 1, l, numnodes - amt + i);
                    int rank = rankOfWeight[w];

                    if (!vis[j][rank]) {
                        vis[j][rank] = true;
                        nxt.push_back({j, rank});
                    }
                }
            }

            // Step 2 : Zoom Out
            if (j < 34 && !vis[j + 1][idx]) {
                vis[j + 1][idx] = true;
                nxt.push_back({j + 1, idx});
            }

            // Step 3 : Zoom In
            if (j > 0 && !vis[j - 1][idx]) {
                vis[j - 1][idx] = true;
                nxt.push_back({j - 1, idx});
            }
        }

        cur.swap(nxt);
        nxt.clear();
        d++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[order[i]] << endl;
    }

    return 0;
}