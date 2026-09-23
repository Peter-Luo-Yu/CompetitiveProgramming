#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // problem type: binary search on sorted array

    int t; cin >> t;
    while (t--) {
        ll n, x, y; cin >> n >> x >> y;

        vector<ll> arr (n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        sort (arr.begin(), arr.end());

        ll L = sum - y, R = sum - x;

        //print(arr);
        //cout << L << " " << R << endl;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll idx1 = lower_bound(arr.begin() + i + 1, arr.end(), L - arr[i]) - arr.begin();
            ll idx2 = upper_bound(arr.begin() + i + 1, arr.end(), R - arr[i]) - arr.begin();

            //cout << "i: " << i << " " << idx1 << " " << idx2 << endl;
            ans += idx2 - idx1;
        }

        cout << ans << endl;
    }


    
    return 0;
}
