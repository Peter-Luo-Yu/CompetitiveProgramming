#define LOCAL

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

int n;
vector<ll> dp1, dp2;

void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis) {
    if (vis[s]) return;
    vis[s] = true;

    vector<int> children;

    // First: calculate dp2
    for (auto u : adj[s]) {
        if (vis[u]) continue;

        children.push_back(u);
        dfs(u, adj, vis);

        dp2[s] += max(dp1[u], dp2[u]);
    }

    // Second: calculate dp1 using FINAL dp2[s]
    for (auto u : children) {
        dp1[s] = max(
            dp1[s],
            dp2[u] + 1 + dp2[s] - max(dp1[u], dp2[u])
        );
    }
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "/w", stdout);
    
    cin >> n;
    dp1 = dp2 = vector<ll> (n);

    vector<vector<int>> adj (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis (n);

    dfs(0, adj, vis);
    cout << max(dp1[0], dp2[0]) << endl;


    return 0;
}