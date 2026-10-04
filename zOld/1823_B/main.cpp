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

int ccidx = 0;
void dfs (int s, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &CC) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) {
        dfs(u, adj, vis, CC);
    }
    CC[s] = ccidx;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<vector<int>> adj (n);
        for (int i = 0; i < k; i++) {
            for (int j = i + k; j < n; j += k) {
                adj[i].push_back(j);
                //adj[j].push_back(i);
            }
        }
        print(adj);

        vector<bool> vis (n);
        vector<int> CC (n);

        ccidx = 0;
        for (int i = 0; i < n; i++) {
            dfs(i, adj, vis, CC);
            ccidx++;
        }

        print(CC);

        int numMisplaced = 0;
        for (int i = 0; i < n; i++) {
            if (CC[i] != CC[arr[i] - 1]) {
                numMisplaced++;
            }
        }

        print(numMisplaced);

        if (numMisplaced == 0) {
            cout << 0 << endl;
        }
        else if (numMisplaced == 2) {
            cout << 1 << endl;
        } 
        else{
            cout << -1 << endl;
        }


        space;
    }


    return 0;
}