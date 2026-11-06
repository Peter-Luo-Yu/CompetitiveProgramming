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


struct BinaryLift {
    ll n, l, timer; 
    vector<ll> tin, tout, depth;
    vector<vector<ll>> adj, up;

    BinaryLift (vector<vector<ll>> &g) { 
        n = g.size();
        adj = g;
        preprocess(0);
    }

    void preprocess(ll root) {
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<ll>(l + 1));
        dfs(root, root);
    }

    void dfs(ll v, ll p) {
        tin[v] = ++timer;
        depth[v] = (v == p ? 0 : depth[p] + 1);   
        up[v][0] = p;
        for (ll i = 1; i <= l; ++i) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (ll u : adj[v]) {
            if (u != p) {
                dfs(u, v);
            }
        }

        tout[v] = ++timer;
    }


    bool is_ancestor(ll u, ll v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    ll lca(ll u, ll v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (ll i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    ll dist(ll u, ll v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

void compute_ans(int s, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &cnt, vector<ll> &paths) {
    if (vis[s]) return;
    vis[s] = true;

    ll val = 0;
    for (auto u : adj[s]) {
        compute_ans(u, adj, vis, cnt, paths);
        // ans to parent = sum answers of children
        val += paths[u];
    }
    paths[s] = val + cnt[s];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    ll n, m; cin >> n >> m;

    vector<vector<ll>> adj (n);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    BinaryLift bl (adj);

    vector<ll> cnt (n);
    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        cnt[a]++;
        cnt[b]++;
        cnt[bl.lca(a, b)]--;

        // we could decrement the root twice, becuase parent(root) = root
        if (bl.lca(a, b) != 0) {
            cnt[bl.up[bl.lca(a, b)][0]]--;
        }
    }

    vector<ll> paths (n);
    vector<bool> vis (n);

    print(cnt);

    compute_ans(0, adj, vis, cnt, paths);

    print(paths);

    for (auto p : paths) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}