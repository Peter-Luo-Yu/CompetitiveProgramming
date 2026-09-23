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
        int n; cin >> n;
        vector<ll> arr (n);

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            ans += arr[i];
        }

        for (int k = 0; k < n - 1; k++) {
            ll sum = 0;
            vector<ll> diff (arr.size() - 1);

            for (int i = 0; i < arr.size() - 1; i++) {
                diff[i] = arr[i + 1] - arr[i];
                sum += diff[i];
            }

            if (sum < 0) {
                sum *= -1; ans = max (ans, sum);
                reverse (diff.begin(), diff.end());
                arr = diff;
            } else {
                ans = max (ans, sum);
                arr = diff;
            }

            //print(diff);
            //cout << sum << endl;
        }



        cout << ans << endl;
        
        
    }
    
    return 0;
}
