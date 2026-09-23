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
        int n, j, k; cin >> n >> j >> k;

        vector<int> arr (n); 
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        int target = arr[j - 1];

        sort(arr.begin(), arr.end());

        if (k > 1){
            cout << "YES" << endl;
        } else {
            if (target == arr[arr.size() - 1]){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    

    return 0;
}