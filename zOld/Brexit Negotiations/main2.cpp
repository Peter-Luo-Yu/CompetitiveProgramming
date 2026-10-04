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
    vector<vector<int>> adj(n);
    vector<int> times (n);
    vector<int> outdeg(n);

    for (int i = 0; i < n; i++) {
        int t, m; cin >> t >> m;
        times[i] = t;

        for (int j = 0; j < m; j++) {
            int prereq; cin >> prereq; prereq--;
            adj[i].push_back(prereq);

            // i -> depend, i has dependencies
            // somebody points into dependencies
            outdeg[prereq]++;
        }
    }

    print(outdeg);

    // time, idx
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        if (outdeg[i] == 0) { //no dependencies
            pq.push({times[i], i});
        }
    }

    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        auto [t, idx] = pq.top();
        pq.pop();

        print(i, t, idx, t + i);

        ans = max (ans, t + i);

        // if i is processed, it's dependencies have to satisfy one less meeting
        for (int prereq : adj[idx]) {
            outdeg[prereq]--;
            if (outdeg[prereq] == 0) {
                pq.push({times[prereq], prereq});
            }
        }
    }

    cout << ans << endl;
 
    

    
    return 0;
}