#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;

        
        vector<int> arr (m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        sort (arr.begin(), arr.end());
        
        //print(arr);

        ll ans = 0;
        for (int i = 1; i <= n - 1; i++) { // left half of fence, length goes from 1 -> n - 1
            //cout << i << " " << n - i << " | ";
            
            ll left = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            ll right = lower_bound(arr.begin(), arr.end(), n - i) - arr.begin();

            //cout << left << " " << right << " ";

            ll x = m - left, y = m - right;

            //cout << x << " " << y << endl;

            ans += x * y - min (x, y);
        }

        cout << ans << endl;

        //space;
    }

    


    return 0;
}
