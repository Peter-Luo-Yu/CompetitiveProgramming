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
        vector<ll> prefix (n + 1);
        map<ll, ll> mp;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            prefix[i + 1] = prefix[i] + arr[i];
        }

        ll ans = 0;

        // want prefix[r] - prefix[l] = 47
        // prefix[l] = prefix[r] - 47
        // remember map tracks the freq of each prefix sum
        // i is prefix[r], but is there a corresponding prefix[l] that equals prefix[r] - 47
        
        for (int i = 0; i <= n; i++) {
            if (mp.count(prefix[i] - 47) > 0) {
                ans += mp[prefix[i] - 47];
            }
            mp[prefix[i]]++;
        }
    
        cout << ans << endl;
    }
    
    return 0;
}
