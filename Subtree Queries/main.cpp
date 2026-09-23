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

struct SegTree {
    ll n;
    vector<ll> lazy, tree;

    void init(ll x) {
        n = x;
        lazy = tree = vector<ll> (4*n);
    } 

    void apply (ll v, ll len, ll val) {
        tree[v] += len * val;
        lazy[v] += val;
    }

    void push (ll v, ll l, ll r) {
        ll m = (l + r) / 2;
        apply (2 * v, m - l + 1, lazy[v]);
        apply (2 * v + 1, r - m, lazy[v]);
        lazy[v] = 0;
    }

    void add (ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            apply (v, r - l + 1, val);
        }
        else {
            push(v, l, r);
            ll m = (r + l) / 2;
            add (2 * v, l, m, ql, qr, val);
            add (2 * v + 1, m + 1, r, ql, qr, val);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    void add (ll ql, ll qr, ll val) {
        add (1, 0, n - 1, ql, qr, val);
    }

    ll sum (ll v, ll l, ll r, ll ql, ll qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll m = (l + r) / 2;
            return sum (2 * v, l, m, ql, qr) + sum (2 * v + 1, m + 1, r, ql, qr);
        }
    }

    ll sum (ll ql, ll qr) {
        return sum (1, 0, n - 1, ql, qr);
    }
};

vector<int> order;

void dfs (ll s, vector<vector<ll>> &adj, vector<bool> &vis, vector<ll> &sizes) {
    if (vis[s]) return;
    vis[s] = true;

    order.push_back(s);

    ll sz = 0;
    for (auto u : adj[s]) {
        dfs (u, adj, vis, sizes);
        sz += sizes[u];
    }

    sz += 1;

    sizes[s] = sz;

}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, q; cin >> n >> q;
    vector<ll> values (n);
    for (ll i = 0; i < n; i++) cin >> values[i];

    vector<vector<ll>> adj (n);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    print(values);
    print(adj);

    // need to find subtree sizes
    vector<bool> vis (n);
    vector<ll> sizes (n);
    dfs (0, adj, vis, sizes);
    print(sizes);


    // order of dfs, order[i] is the orig index 
    print(order);
    vector<ll> temp (n);
    for (int i = 0; i < n; i++) {
        temp[i] = values[order[i]];
    }
    values = temp;

    for (int i = 0; i < n; i++) {
        temp[i] = sizes[order[i]];
    }
    sizes = temp;

    // segtree setup
    SegTree seg;
    seg.init(n);
    for (ll i = 0; i < n; i++) {
        seg.add(i, i, values[i]);
    }


    // now we want to convert the orig index -> back to the order idx
    vector<int> pos (n);
    for (int i = 0; i < n; i++) {
        pos[order[i]] = i;
    }
    
    while (q--) {
        ll type; cin >> type;

        // the issue here is that node is no longer matched up with the original node pos
        if (type == 1) {
            ll node, val; cin >> node >> val;
            node--;

            node = pos[node];

            ll prev = seg.sum(node, node);

            seg.add(node, node, -prev);
            seg.add(node, node, val);
        }
        else {
            ll node; cin >> node; node--;

            node = pos[node];

            ll sz = sizes[node];

            cout << seg.sum(node, node + sz - 1) << endl;
        }

    }


    return 0;
}