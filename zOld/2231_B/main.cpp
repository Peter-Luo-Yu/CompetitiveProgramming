#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        vector<int> vis (n, -1);
        int numvis = 0;

        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cur = arr[i];
                vis[i] = 1;
                numvis++;
            } else {
                if (arr[i] >= cur) {
                    cur = arr[i];
                    vis[i] = 1;
                    numvis++;
                }
            }
        }

        //print(arr); print(vis); space;

        int idx = -1;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == -1) {
                idx = i; 
                break;
            }
        }

        if (idx != -1) {

            
            cur = -1;
            for (int i = idx; i < n; i++) {
                if (vis[i] != -1) continue;

                if (cur == -1) {
                    cur = arr[i];
                    vis[i] = 2;
                    numvis++;
                } else {
                    if (arr[i] >= cur) {
                        cur = arr[i];
                        vis[i] = 2;
                        numvis++;
                    }
                }
            }
        }

        print(vis);
        cout << numvis << endl;

        if (numvis != n) {
            cout << "NO" << endl;
            space;
            continue;
        } 
        


        int lb = 0, ub = 1e9;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 2) {
                if (vis[i - 1] == 1) {
                    lb = max(lb, arr[i - 1] - arr[i]);
                }
                if (i != n - 1 && vis[i + 1] == 1) {
                    ub = min(ub, arr[i + 1] - arr[i]);
                }
            }
        }
        cout << "lb: " << lb << " ub: " << ub << endl;


        if (lb <= ub) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


        space;
    }


    return 0;
}
