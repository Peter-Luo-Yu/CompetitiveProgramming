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

        vector<vector<int>> arr (n, vector<int> (2));

        for (int i = 0; i < n; i++){
            cin >> arr[i][0] >> arr[i][1];
        }

        sort (arr.begin(), arr.end());

        /*
        for (int i = 0; i < n; i++){
            cout << arr[i][0] << " " << arr[i][1] << endl;
        } cout << endl; 
        */

        int max_width = arr[arr.size() - 1][0];
        int abs_height = 0;

        vector<int> heights;

        for (int i = 1; i <= max_width; i++){
            int max_height = 0;

            for (int j = 0; j < arr.size(); j++){
                if (arr[j][0] >= i){
                    max_height = max (max_height, arr[j][1]);
                }
            }

            heights.push_back(max_height);
            abs_height = max (abs_height, max_height);
        }
        

        heights.push_back(0);

        //print(heights);

        int ans = max_width + abs_height;
        //cout << "before: " << ans << endl;
        for (int i = 0; i < heights.size() - 1; i++){
            ans += heights[i] - heights[i + 1] + 1;
        }

        cout <<  ans << endl;
        //cout << endl;
    }

   
    

    return 0;
}