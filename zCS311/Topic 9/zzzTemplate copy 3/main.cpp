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

// Source: https://aryansh.gitbook.io/informatics-notes/binary-lifting/binary-lifting-gold-part-2

int n; 
const int mxn = 2e5 + 5, mxe = log2(mxn) + 5; 
vector<vector<int>> adj; 

vector<vector<int>> up (mxn, vector<int> (mxe, -1));
vector<int> depth (mxn);
vector<bool> vis (mxn);

void dfs(int v, int p, int d) { // keep track of current, parent, and depth
    up[v][0] = p; // mark the parent
    depth[v] = d; // mark the depth
    vis[v] = 1; // mark the node as visited
    for(int u: adj[v]) if(!vis[u]) dfs(u,v,d+1); // visit all unvisited children
}

int lift(int node, int dist) { // pass node and lift
    for(int l = 0; l < mxe; ++l) 
        if(node != -1) if(dist & (1 << l)) 
            node = up[node][l]; // jump up by the power of 2 at this point
    return node; 
}

int lca(int a, int b) {
    a = lift(a, depth[a] - min(depth[a], depth[b])); 
    b = lift(b, depth[b] - min(depth[a], depth[b])); 
    if(a == b) return a;
    for(int l = mxe - 1; l >= 0; --l)
        if(up[a][l] != up[b][l]) a = up[a][l], b = up[b][l]; 
    return up[a][0]; 
}


int distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a,b)]; 
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n; 
    adj.resize(n);

    for(int i = 0; i < n - 1; ++i) { 
        int a,b; cin >> a >> b, --a, --b; 
        adj[a].push_back(b);
        adj[b].push_back(a); 
    } 

    print(n);
    print(adj);

    dfs(0,-1,0);

    for(int l = 1; l < mxe; ++l) 
        for(int i = 0; i < n; ++i) 
            if(up[i][l-1] != -1) up[i][l] = up[up[i][l-1]][l-1];
    
    ll ans = 0;
    for(int i = 1; i <= n / 2; ++i) {
        for (int j = i + i; j <= n; j += i) {
            int dist = distance(i - 1, j - 1);
            print(i, j, dist);
            ans += dist + 1;
        }
    }

    print(ans);

    cout << ans << endl;


    return 0;
}