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

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}
        sort (arr.begin(), arr.end(), greater<>());

        int sum = 0; 
        for (int i = 0; i < n; i++) {
            if (arr[i] + sum <= k) {
                sum += arr[i];
            } else {
                break;
            }
        }

        //print(arr);
        cout << k - sum << endl;
    }
    

    return 0;
}