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
#define lll __int128_t
#define ld long double
#define endl "\n"

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}


struct SegmentTree {
    ll n;
    vector<ll> lazy, tree;
 
    void init(ll x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }
 
    void apply(ll v, ll len, ll val) { // changed for max seg tree
        tree[v] += val;
        lazy[v] += val;
    }
 
    void push(ll v, ll l, ll r) {
        ll mid = (l + r) / 2;
        apply(2 * v, mid - l + 1, lazy[v]);
        apply(2 * v + 1, r - mid, lazy[v]);
        lazy[v] = 0;
    }
 
    void add(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, val);
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            add(2 * v, l, mid, ql, qr, val);
            add(2 * v + 1, mid + 1, r, ql, qr, val);
            tree[v] = max(tree[2 * v], tree[2 * v + 1]); // here as well
        }
    }
 
    void add(ll ql, ll qr, ll val) {
        add(1, 0, n - 1, ql, qr, val);
    }
 
    // sum actually returns the max now :)

    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return -1e18;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            return max(sum(2 * v, l, mid, ql, qr), sum(2 * v + 1, mid + 1, r, ql, qr));
        }
    }
 
    ll sum(ll ql, ll qr) {
        return sum(1, 0, n - 1, ql, qr);
    }
 
    ll findk (ll k) { // 0 indexed
        ll v = 1, l = 0, r = n - 1;
 
        while (l < r) {
            push(v, l, r);
            ll mid = (l + r) / 2;
            if (tree[2 * v] > k) { // left side has more than k active
                v = 2 * v;
                r = mid;
            }
            else {
                k -= tree[2 * v];
                v = 2 * v + 1;
                l = mid + 1;
            }
        }
 
        return l;
    }

    
    void build(ll v, ll l, ll r, const vector<ll>& a) { // set leaves from a[0..n-1]
        lazy[v] = 0;
        if (l == r) { tree[v] = a[l]; return; }
        ll mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    void build(const vector<ll>& a) {
        build(1, 0, n - 1, a);
    }

    void erase(ll pos) {
        add(pos, pos, -(ll)1e12);
    }


    // push every position in [ql, qr] whose value is >= T
    void collect(ll v, ll l, ll r, ll ql, ll qr, ll T, vector<int>& out) {
        if (qr < l || ql > r || tree[v] < T) return;
        if (l == r) { out.push_back((int)l); return; }
        push(v, l, r);
        ll mid = (l + r) / 2;
        collect(2 * v, l, mid, ql, qr, T, out);
        collect(2 * v + 1, mid + 1, r, ql, qr, T, out);
    }

    void collect(ll ql, ll qr, ll T, vector<int>& out) {
        collect(1, 0, n - 1, ql, qr, T, out);
    }
 
};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        
        int idx = -1, most = -1;
        vector<int> dist (n - 1);

        SegmentTree segtree;
        segtree.init(n - 1);

        for (int i = 0; i < n - 1; i++) {
            int d = abs(arr[i] - arr[i + 1]);
            
            if (d > most) {
                most = d;
                idx = i;
            }

            dist[i] = d;
            segtree.add(i, i, dist[i]);
        }

        print(arr);
        print(dist, idx);
        //print(segtree.tree);

        print(segtree.sum(0, n - 1));

        // try a brute force
        int l = idx + 1, r = idx + 1;
        int best = most;

        //print(l, r);

        for (r = l; r < n; r++) {
            print(l, r);

            // I swapped it first here
            int valL = 2 * arr[r];
            int valR = 2 * arr[l];

            int origl = -1, origr = -1;
            int distl = -1, distr = -1;
 
            int between = -1; // dist between
            if (r > l) {
                between = segtree.sum(l, r - 1);
            }
            between *= 2;

            if (l > 0) {
                origl = dist[l - 1];
                distl = abs(arr[l - 1] - valL);

                segtree.add(l - 1, l - 1, -1 * segtree.sum(l - 1, l - 1));
                segtree.add(l - 1, l - 1, distl);
            }
            if (r < n - 1) { 
                origr = dist[r];
                distr = abs(arr[r + 1] - valR);

                segtree.add(r, r, -1 * segtree.sum(r, r));
                segtree.add(r, r, distr);
            }
            
            print(origl, origr, distl, distr, between);


            if (origl != -1) {
                segtree.add(l - 1, l - 1, -1 * segtree.sum(l - 1, l - 1));
                segtree.add(l - 1, l - 1, origl);
            }
            if (origr != -1) { 
                segtree.add(r, r, -1 * segtree.sum(r, r));
                segtree.add(r, r, origr);
            }

            
            
            int curD = -1;
            if (distl != -1) {
                curD = distl;
            }
            if (distr != -1) {
                curD = max (curD, distr);
            }
            if (between >= 0) {
                curD = max(curD, between);
            }

            best = min(best, curD);
        
            print(best, curD);
        }

        print(best);


        // now try it on the reverse: 
        reverse(arr.begin(), arr.end());
        print(arr);

        idx = -1, most = -1;
        dist = vector<int> (n - 1);

        segtree.init(n - 1);

        for (int i = 0; i < n - 1; i++) {
            int d = abs(arr[i] - arr[i + 1]);
            
            if (d > most) {
                most = d;
                idx = i;
            }

            dist[i] = d;
            segtree.add(i, i, dist[i]);
        }

        print(arr);
        print(dist, idx);
        //print(segtree.tree);

        print(segtree.sum(0, n - 1));

        // try a brute force
        l = idx + 1, r = idx + 1;

        //print(l, r);

        for (r = l; r < n; r++) {
            print(l, r);

            // I swapped it first here
            int valL = 2 * arr[r];
            int valR = 2 * arr[l];

            int origl = -1, origr = -1;
            int distl = -1, distr = -1;
 
            int between = -1; // dist between
            if (r > l) {
                between = segtree.sum(l, r - 1);
            }
            between *= 2;

            if (l > 0) {
                origl = dist[l - 1];
                distl = abs(arr[l - 1] - valL);

                segtree.add(l - 1, l - 1, -1 * segtree.sum(l - 1, l - 1));
                segtree.add(l - 1, l - 1, distl);
            }
            if (r < n - 1) { 
                origr = dist[r];
                distr = abs(arr[r + 1] - valR);

                segtree.add(r, r, -1 * segtree.sum(r, r));
                segtree.add(r, r, distr);
            }
            
            print(origl, origr, distl, distr, between);


            if (origl != -1) {
                segtree.add(l - 1, l - 1, -1 * segtree.sum(l - 1, l - 1));
                segtree.add(l - 1, l - 1, origl);
            }
            if (origr != -1) { 
                segtree.add(r, r, -1 * segtree.sum(r, r));
                segtree.add(r, r, origr);
            }

            
            
            int curD = -1;
            if (distl != -1) {
                curD = distl;
            }
            if (distr != -1) {
                curD = max (curD, distr);
            }
            if (between >= 0) {
                curD = max(curD, between);
            }

            best = min(best, curD);
        
            print(best, curD);
        }

        print(best);

        cout << best << endl;

        space;
    }


    return 0;
}