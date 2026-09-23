#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;

        vector<vector<int>> grid (n, vector<int> (m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                char val; cin >> val;

                grid[i][j] = val - '0';
            }
        }

        bool failed = false;

        for (int i = grid.size() - 1; i > 0; i--){
            for (int j = grid[i].size() - 1; j > 0; j--){
                bool up = true;
                bool left = true;
                
                if (grid[i][j] == 1){
                    // check up and check left
                    for (int k = i; k >= 0; k--){
                        if (grid[k][j] == 0){
                            up = false;
                            break;
                        }
                    }

                    for (int k = j; k >= 0; k--){
                        if (grid[i][k] == 0){
                            left = false;
                            break;
                        }
                    }
                }

                if (!up && !left){
                    failed = true;
                }

                if (failed){
                    break;
                }
            }
            if (failed){
                break;
            }
        }

        if (failed){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        /*
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << grid[i][j] << " ";
            } cout << endl;
        } cout << endl;
         */
    }

    return 0;
}