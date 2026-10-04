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

void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) dfs (u, adj, vis, topo);
    topo.push_back(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> adj (n);
        vector<bool> vis (n);
        vector<int> topo;

        vector<pair<int, int>> undir;
        for (int i = 0; i < m; i++) {
            int type; cin >> type;
            int a, b; cin >> a >> b; a--, b--;
            if (type == 0) {
                undir.push_back({a, b});
            } else {
                adj[a].push_back(b);
            }
        }

        for (int i = 0; i < n; i++) {
            dfs(i, adj, vis, topo);
        }
        reverse(topo.begin(), topo.end());

        vector<int> idx (topo.size());
        for (int i = 0; i < topo.size(); i++) {
            idx[topo[i]] = i;
        }

        bool cycle = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                if (idx[i] >= idx[adj[i][j]]) {
                    cycle = true;
                }
            }
        }

        print(topo); 

        if (cycle) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for (int i = 0; i < undir.size(); i++) {
            if (idx[undir[i].first] < idx[undir[i].second]) {
                cout << undir[i].first + 1 << " " << undir[i].second + 1 << endl;
            } else {
                cout << undir[i].second + 1 << " " << undir[i].first + 1 << endl;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                cout << i + 1 << " " << adj[i][j] + 1 << endl;
            }
        }

    }
    

    
    return 0;
}