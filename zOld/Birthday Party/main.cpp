#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

void dfs (int s, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[s]) return;

    vis[s] = true;

    for (auto x : adj[s]) {
        dfs (x, adj, vis);
    }   
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int p , c;
    cin >> p >> c;

    while (p != 0 && c != 0) {
        

        vector<vector<int>> adj (p);
        for (int i = 0; i < c; i++) {
            int a, b; cin >> a >> b; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool ans = true;

        for (int i = 0; i < p - 1; i++) {
            for (int j = i + 1; j < p; j++) {
                vector<vector<int>> adj2 = adj;

                //cout << "i: " << i << " j: " << j << endl;

                for (int a = 0; a < adj2.size(); a++) {
                    if (a == i) {
                        
                        for (int b = 0; b < adj2[a].size(); b++) {
                            if (adj2[a][b] == j) {
                                adj2[a].erase(adj2[a].begin() + b);  
                                
                                break;  
                            }
                        }
                    }
                    if (a == j) {
                        
                        for (int b = 0; b < adj2[a].size(); b++) {
                            if (adj2[a][b] == i) {
                                adj2[a].erase(adj2[a].begin() + b);
                                
                                break;  
                            }
                        }
                    }
                    
                }

                //printG(adj2);

                vector<bool> vis (p);
                dfs (0, adj2, vis);

                bool failed = false;

                for (int i = 0; i < vis.size(); i++) {
                    if (!vis[i]) {
                        failed = true;
                    }
                }

                if (failed) {
                    //cout << "failed" << endl;
                    ans = false;
                } else {
                    //cout << "good" << endl;
                }
                
            }
        }

        if (ans == false) {
            cout << "YES" << endl;
        } else {
            cout <<  "NO" << endl;
        }


        cin >> p >> c;
        
    }
    

    return 0;
}