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
    for (auto u : adj[s]) dfs(u, adj, vis, topo);
    topo.push_back(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<string> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    print(arr);

    vector<vector<int>> adj (26);
    //set<pair<int, int>> st;

    bool failed = false;

    for (int i = 0; i < n - 1; i++) {
        bool same = true;

        for (int j = 0; j < min(arr[i].size(), arr[i + 1].size()); j++) {
            if (arr[i][j] != arr[i + 1][j]) {
                //if (st.count({arr[i][j] - 'a', arr[i + 1][j] - 'a'}) == 0) {
                    adj[arr[i][j] - 'a'].push_back(arr[i + 1][j] - 'a');
                    //st.insert({arr[i][j] - 'a', arr[i + 1][j] - 'a'});
                    same = false;
                    break;
                
            }
        }

        if (same && (arr[i].size() > arr[i + 1].size())) {
            failed = true;
        }
    }

    print(adj);

    vector<bool> vis (26);
    vector<int> topo;

    for (int i = 0; i < 26; i++) {
        dfs(i, adj, vis, topo);
    }
    reverse(topo.begin(), topo.end());

    vector<int> idx (26);
    for (int i = 0; i < topo.size(); i++) idx[topo[i]] = i;

    bool cycle = false;
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (idx[i] >= idx[adj[i][j]]) {
                cycle = true;
            }
        }
    }

    print(topo);

    if (cycle || failed) {
        cout << "Impossible" << endl;
    }
    else {
        for (auto t : topo) {
            cout << (char) (t + 'a');
        }
        cout << endl;
    }
   
    return 0;
}