#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        vector<vector<int>> arr (n, vector<int> (2));
        vector<vector<double>> avg (n, vector<double> (2));

        for (int i = 0; i < n; i++){
            int a, b; cin >> a >> b;

            arr[i][0] = a; arr[i][1] = b;
            avg[i][0] = (double) (a+b)/2; avg[i][1] = i;
        }

        sort (avg.begin(), avg.end());

        /*
        for (int i = 0; i < n; i++){
            cout << arr[i][0] << " " << arr[i][1] << endl;
        }
        for (int i = 0; i < n; i++){
            cout << avg[i][0] << " " << avg[i][1] << endl;  
        }

        cout << "ans: " << endl;
        */
       
        for (int i = 0; i < n; i++){
            cout << arr[avg[i][1]][0] << " " << arr[avg[i][1]][1] << " ";
        }
        
        cout << endl;

    }

    return 0;
}