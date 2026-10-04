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

// topo sort

void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) dfs(u, adj, vis, topo);
    topo.push_back(s);
}


struct DSU {
    int n;
    vector<int> parent, sz;

    void setup (int x) {
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


struct SegmentTree {
    ll n;
    vector<ll> lazy, tree;
 
    void init(ll x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }
 
    void apply(ll v, ll len, ll val) {
        tree[v] += len * val;
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
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }
 
    void add(ll ql, ll qr, ll val) {
        add(1, 0, n - 1, ql, qr, val);
    }
 
    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            return sum(2 * v, l, mid, ql, qr) + sum(2 * v + 1, mid + 1, r, ql, qr);
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
 
};

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // SMALLEST PRIME FACTOR

    int N = 1e2;
    vector<int> factors(N);

    for (int i = 2; i <= N; i++) {
		if (factors[i] == 0) {
			for (int j = i; j <= N; j += i) { factors[j] = i; }
		}
	}

    // DIJKSTRA
     
    vector<bool> vis (n);
    vector<ll> dist (n, 1e18);
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // distance - idx
 
    dist[0] = 0;
    vis[0] = true;
    pq.push({0, 0});
 
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
 
        // to not TLE
        if (d != dist[cur]) continue;
 
        for (auto next : adj[cur]) {
            if (vis[next.first]) continue;
 
            if (dist[cur] + next.second < dist[next.first]) {
                dist[next.first] = dist[cur] + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }


    // Kruskals: unite if not the same

    for (auto e : edges) {
        if (!dsu.same(e.a, e.b)) {
            dsu.unite(e.a, e.b);
            ans += e.w;
        }
    }


    // mt

    mt19937 rng ((ll) new char);

    uniform_int_distribution<ll> rand (1, 5);

    cout << rand(rng) << endl;


    return 0;
}