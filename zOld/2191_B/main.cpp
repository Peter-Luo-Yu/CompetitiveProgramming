#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        sort (arr.begin(), arr.end());

        bool failed = false;

        for (int i = 1; i <= n - 1; i++) {
            vector<int> arr1 (arr.begin(), arr.begin() + i);
            vector<int> arr2 (arr.begin() + i, arr.end());

            
            int mex1, mex2;

            for (int j = 0; j < 105; j++) {
                bool found = false;

                for (int k = 0; k < arr1.size(); k++) {
                    if (arr1[k] == j) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    mex1 = j;
                    break;
                }
            }
            for (int j = 0; j < 105; j++) {
                bool found = false;

                for (int k = 0; k < arr2.size(); k++) {
                    if (arr2[k] == j) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    mex2 = j;
                    break;
                }
            }
            
            /*
            print(arr1); print(arr2); 
            cout << "m1: " << mex1 << " m2: " << mex2 << endl;
            cout << endl;
            */

            if (mex1 == mex2) {
                failed = true;
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    

    return 0;
}