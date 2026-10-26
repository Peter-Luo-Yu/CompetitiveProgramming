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

struct DSU {
    int n;
    vector<int> parent, sz;

    void init (int x) {
        n = x;
        parent = sz = vector<int> (n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find (int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }

    bool same (int a, int b) {
        return find(a) == find(b);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;

        if (sz[a] < sz[b]) swap (a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }
};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    ll n, k; cin >> n >> k;
    vector<ll> value (n);
    for (ll i = 0; i < n; i++) cin >> value[i];

    vector<vector<ll>> adj (n);
    vector<ll> deg (n); 
    for (ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    print(deg);

    // Observation 1: we have a single cycle with trees hanging off of it
    // to find who is in a cycle vs who is not
    // we can continuous to peel all the deg 1 edges away 
    // until we are only left with a cycle
    
    vector<bool> onCycle (n, true);
    queue<ll> q;
    for (ll i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        ll cur = q.front(); 
        q.pop();

        onCycle[cur] = false;

        for (auto next : adj[cur]) {
            deg[next]--;

            if (deg[next] == 1) {
                q.push(next);
            }
        }
    }

    print(onCycle);

    // Observation 2: given an vertex we want to know on which group it is from
    // if both vertices in same group -> 1 poss
    // if both vertices in diff groups -> 2 poss
    // why because same group there is one way through the only cycle node 
    // that branches off into the tree both vertices are in
    // diff group allows 2 different traversal ccw and cc around the cycle
    // if both vertices are on the cycle they will be in diff groups
    // because we are only unioning the separate trees rooted at a single cycle node
    // but not the cycle nodes itself

    DSU dsu;
    dsu.init(n);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < adj[i].size(); j++) {
            if (!onCycle[i] || !onCycle[adj[i][j]]) {
                dsu.unite(i, adj[i][j]);
            }
        }
    }

    // we are tracking the freq of each cost
    // to abuse the fact that ae - as = k
    // so ans = cnt[x] * cnt[k - x]
    
    map<ll, ll> cnt; // val -> cnt
    map<pair<ll, ll>, ll> Gcnt; // group, val -> cnt
    
    // now we can cleverly find differnet cnt = cnt - Gcnt

    for (ll i = 0; i < n; i++) {
        Gcnt[{dsu.find(i), value[i]}]++;
        cnt[value[i]]++;
    }

    ll same = 0, diff = 0;

    print(k);
    for (auto &[key, c] : Gcnt) {
        print(key, c);

        ll g = key.first;  
        ll val = key.second - k; // target val
        
        // look for same
        auto it = Gcnt.find({g, val}); 
        if (it != Gcnt.end()) {
            same += c * (it -> second);

            print(it -> second);
        }

        // look for different
        // num diff = totalcnt[opposite] - samegroupcnt[opposite]
        auto yt = cnt.find(val);
        if (yt != cnt.end()) {
            if (it != Gcnt.end()) {
                ll amt = (yt -> second - it -> second);
                diff += c * amt;
                print(yt -> second, it -> second);
            }
            else {
                ll amt = (yt -> second);
                diff += c * amt;
                print(yt -> second);
            }
        }
    }

    print(same, diff);

    ll ans = same + 2 * diff;

    cout << ans << endl;

    return 0;
}