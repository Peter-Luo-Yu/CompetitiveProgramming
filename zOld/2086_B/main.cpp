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
        ll n, k, x; cin >> n >> k >> x;

        ll arrsum = 0;
        vector<ll> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arrsum += arr[i];
        }
        reverse(arr.begin(), arr.end());
    
        //cout << "arrsum: " << arrsum << endl;
        //cout << "arr: "; print(arr);
        
        ll sum = 0, cnt = 0; // num positions that don't work


        ll times = (x / arrsum) - 1;

        if (times > 0) {
            sum += arrsum * times;
            cnt += n * times;
        }
        
        
        //cout << "sum: " << sum << " cnt: " << cnt << endl;

        int idx = 0;
        while (sum < x) {
            sum += arr[idx % arr.size()];
            //cout << sum << endl;
            if (sum < x) {
                idx++; cnt++;
            }
        }
            

        ll ans = max(n * k - cnt, 0LL);

        cout << ans << endl;
        
        //space;
    }


    return 0;
}
