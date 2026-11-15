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


#define int long long
#define ld long double
#define endl "\n"

struct guy {
    int id;
    int sal;
    int height;

    bool operator<(const guy &other) const {
        if (height != other.height) return height < other.height;
        return sal < other.sal;
    }
};

int n;
vector<vector<int>> adj;
vector<int> dp;
vector<bool> vis;

void dfs (int s) { // calculate subtree size
    if (vis[s]) return;
    vis[s] = true;

    int sz = 0;
    for (auto u : adj[s]) {
        if (!vis[u]) dfs(u);
        sz += dp[u];
    }

    dp[s] = sz + 1;
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q; cin >> n >> q;

    vector<guy> arr (n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].sal >> arr[i].height;
    }

    sort (arr.begin(), arr.end());

    map<int, int> index; // maps ID -> index
    vector<int> heights (n), salary (n); 
    for (int i = 0; i < n; i++) {
        heights[i] = arr[i].height;
        salary[i] = arr[i].sal;
        index[arr[i].id] = i;
    }

    /*
    for (auto a : arr) { 
        cout << a.id << " " << a.sal << " " << a.height << endl;
    } */   

    print(index);
    print(heights);
    print(salary);


    vector<int> parent (n, -1);

    // the boss is the lowest earning guy who is taller than you
    map<int, int> mp; // sal -> idx;
    for (int i = n - 1; i >= 0; i--) {
        auto it = mp.upper_bound(arr[i].sal); // stricly greater than cur salary
        if (it != mp.end()) {
            parent[i] = it -> second;
        }
        mp[arr[i].sal] = i;
    }

    print(parent);

    
    adj = vector<vector<int>> (n);
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }

    print(adj);

    vis = vector<bool> (n);
    dp = vector<int> (n);
    dfs(n - 1);

    print(dp);


    while (q--) {
        int id; cin >> id;

        int pos = index[id];
        int h = heights[pos];

        int boss = parent[pos];

        if (boss == -1) {
            cout << 0 << " ";
        } 
        else {
            cout << arr[boss].id << " ";
        }

        cout << dp[pos] - 1 << endl;

    }
    


    return 0;
}