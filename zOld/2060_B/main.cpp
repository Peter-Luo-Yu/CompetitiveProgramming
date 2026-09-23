#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> arr (n, vector<int> (m));
        vector<int> order (n);

        for (int i = 0; i < n; i++) {
            order[i] = i;
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            sort (arr[i].begin(), arr[i].end());
        }

        //print(order); print2d(arr);
       

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i][0] > arr[j][0]) {
                    swap(arr[i], arr[j]);
                    swap(order[i], order[j]);
                }
            }
        }

        //print(order); print2d(arr);

        bool failed = false;
        int prev = -1;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {

                if (prev == -1) {
                    prev = arr[i][j];
                    continue;
                } 

                if (arr[i][j] <= prev) {
                    failed = true;
                    break;
                } else {
                    prev = arr[i][j];
                }
            }
            if (failed) break;
        }


        if (failed) {
            cout << "-1" << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << order[i] + 1 << " ";
            }
            cout << endl;
        }

    }
    
    
    return 0;
}
