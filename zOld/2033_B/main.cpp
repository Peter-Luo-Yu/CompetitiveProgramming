#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        vector<vector<int>> arr (n, vector<int> (n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        
        // checking diagonals that begin on the top row
        int ops = 0;

        for (int j = 0; j < n; j++){
            int Min = 1e9;
            int i = 0;
            int jj = j;

            while (jj < n && i < n){
                //cout << "i: " << i << " j: " << jj << endl;
                Min = min(Min, arr[i][jj]);
                i++; jj++;
            }
            //cout << " min: " << Min << endl;
            if (Min < 0){
                ops += (Min * -1);
            }
           
        }

        for (int i = 1; i < n; i++){
            int Min = 1e9;
            int j = 0;
            int ii = i; 

            while (j < n && ii < n){
                //cout << "i: " << ii << " j: " << j << endl;
                Min = min(Min, arr[ii][j]);
                ii++; j++;
            }
            if (Min < 0){
                ops += (Min * -1);
            }
            
        }

        cout << ops << endl;
        /*
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }*/

    }
    

    return 0;
}