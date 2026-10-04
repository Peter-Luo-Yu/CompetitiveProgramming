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
        // bitwise AND of all n elements must be zero, and maximize the sum
        // you know the (max) sum must be 2^k - 1, because we want all k bits turned on
                
        // tc1: n = 2, k = 2
        // there are two 1's. we can split: case 1 - all ones, 
        

        ll n, k; cin >> n >> k;

        ll ans = n;
        ll MOD = 1e9 + 7;

        for (int i = 0; i < k - 1; i++) {
            ans *= n;
            ans %= MOD;
        }

        cout << ans << endl;


    }
    


    return 0;
}
