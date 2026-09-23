#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

void dfs (vector<vector<int>> arr, vector<vector<int>> tracker){
    
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t; 
    while (t--){
        int n, m; cin >> n >> m; 

        vector<vector<char>> arr (n, vector<char> (m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }
        
        vector<vector<int>> tracker (n, vector<int> (m, -1));

        int j = 0;
        for (int i = 0; i < m; i++){
            if (i == 0 || i == m - 1){
                if (arr[i][j] == 'U' || arr[i][j] == 'L'){

                }
            }
            else if (arr[i][j] == 'U'){

            }
        }


        /*
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << tracker[i][j] << " ";
            }
            cout << endl;
        }*/



    }
    

    return 0;
}