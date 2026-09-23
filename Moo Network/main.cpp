#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define print(...) 6
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

struct Edge {
    ll a, b, w;
};

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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<pair<ll, ll>> pos (n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    sort (pos.begin(), pos.end()); // sort by xcor
    //print(pos);

    vector<Edge> edges; 
    
    // y goes from 0 - 10, tracks last cow with specific y coordinate
    // last[y] = {x, y, idx}
    vector<vector<ll>> last (11, vector<ll> (3, -1)); 

    for (int i = 0; i < n; i++) {
        ll x = pos[i].first, y = pos[i].second;

        for (int yy = 0; yy <= 10; yy++) {
            if (last[yy][0] != -1) {
                ll xl = last[yy][0], yl = last[yy][1], idx = last[yy][2];
                ll d = (x - xl) * (x - xl) + (y - yl) * (y - yl);
                edges.push_back({i, idx, d});
            }
        }

        last[y] = {x, y, i};
    }

    sort (edges.begin(), edges.end(), [] (Edge &a, Edge &b) {return a.w < b.w;});

    //for (auto e : edges) cout << e.a << " " << e.b << " " << e.w << endl;
    

    DSU dsu;
    dsu.setup(n);

    ll ans = 0;
    for (auto e : edges) {
        if (!dsu.same(e.a, e.b)) {
            dsu.unite(e.a, e.b);
            ans += e.w;
        }
    }

    cout << ans << endl;
    
    return 0;
}