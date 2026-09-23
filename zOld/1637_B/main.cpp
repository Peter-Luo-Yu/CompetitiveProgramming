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
        int n; cin >> n;

        vector<int> arr (n);
        
        for (int i = 0; i < n; i++) cin >> arr[i];
        //print(arr);

        ll ans = 0;

        for (int k = 1; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {

                for (int j = i; j < i + k; j++) {
                    //cout << arr[j] << " ";

                    if (arr[j] == 0) {
                        ans += (1);
                    } else {
                        ans += 0;
                    }
                }
                ans += k;
                //cout << endl;
            }
        }

        cout << ans << endl;
        
    }

    
    return 0;
}
