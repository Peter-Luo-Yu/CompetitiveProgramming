//#define LOCAL

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


int n, m, c; 
vector<vector<int>> adj;
vector<int> topo;
vector<bool> vis;
    
void dfs (int s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) dfs(u);
    topo.push_back(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    cin >> n >> m >> c;
    adj = vector<vector<int>> (n);
    vis = vector<bool> (n);

    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<pair<int, int>, int> mp;
    for (int i = 0; i < c; i++) {
        int a, b, x; cin >> a >> b >> x; a--, b--;
        mp[{a, b}] = max(mp[{a,b}], x);
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        dfs(i);
    }
    reverse(topo.begin(), topo.end());

    
    vector<int> ans = arr;

    print(topo);
    for (auto cur : topo) {
        for (auto next : adj[cur]) {
            ans[next] = max(ans[next], ans[cur] + mp[{cur, next}]);
        }
    }

    print(ans);
    
    for (auto a : ans) {
        cout << a << endl;
    }


    return 0;
}