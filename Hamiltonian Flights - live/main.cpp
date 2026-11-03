// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define int long long

inline int get(int val, int i){
    return (val >> i) & 1;
}

const int mod = 1e9 + 7;

inline void add(int& x, int y) {
    x += y;
    if(x > mod) x -= mod;
}

// define dp[S][i] = number of paths visiting all cities in set S ending at i    
int dp[(1 << 20)][20];


signed main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
    }

    dp[1][0] = 1;


    // implement push dp? (S,i) contributes to (S U {j}, j)
    for (int S = 0; S < (1 << n); ++S) {
        if (get(S,0) == 0) continue;
        // iterate over bits
        for (int i = 0; i < n; i++) {
            if (get(S,i) == 0) continue; // i must be in S (otherwise not a valid state)
            // state (S,i): Find contribution to (S U {j}, j) over all possible j
            for (int j : adj[i]) {
                if(get(S, j)) continue;
                add(dp[S | (1 << j)][j], dp[S][i]); 
            }
            
        }
    }
    cout << dp[(1<<n)-1][n-1] << "\n";
}
