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

void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &dams) {
    if (vis[s]) return;
    vis[s] = true;

    // counting the dams of the children
    int numChildren = 0;
    int numDams = 0;
    int loc = 0;
    for (auto u : adj[s]) {
        if (vis[u]) continue;

        dfs (u, adj, vis, dams);
        if (dams[u]) {
            numDams++;
            loc = u;
        }
        numChildren++;
    }

    print(s, numDams, loc);

    if (numDams == 1 && dams[s] == false && s != 0) {
        dams[loc] = false;
        dams[s] = true;
    }

}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj (n);
        for (int i = 0; i < n - 1; i++) {
            int p; cin >> p; p--;
            adj[i + 1].push_back(p);
            adj[p].push_back(i + 1);
        }

        
        vector<bool> dams (n);
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            int dam; cin >> dam; dam--;
            dams[dam] = true;
        }

        vector<bool> vis (n);
        
        print(dams);
        print(adj);

        for (int i = 0; i < n; i++) {
            dfs(i, adj, vis, dams);
        }

        print(dams);
        space;

        
        if (dams[0]) {
            int num = 0;
            for (int i = 1; i < n; i++) {
                if (dams[i]) {
                    num++;
                }
            }

            cout << num << " ";
            for (int i = 1; i < n; i++) {
                if (dams[i]) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        }
        else {
            int num = 0;
            for (int i = 1; i < n; i++) {
                if (dams[i]) {
                    num++;
                }
            }

            int skip = adj[0][0];
            //cout << skip << endl;

            cout << num - 1 << " ";
            for (int i = 1; i < n; i++) {
                if (dams[i] && i != skip) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;


        }
    }


    return 0;
}