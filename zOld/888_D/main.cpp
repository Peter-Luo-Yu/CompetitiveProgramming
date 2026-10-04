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

    ll n, k; cin >> n >> k;

    if (k == 1) {
        cout << 1 << endl;
    }
    else if (k == 2) {
        // ans = 1 + n choose 2

        ll ans = 1 + n * (n - 1) / 2;
        cout << ans << endl;
    } 
    else if (k == 3) {
        // derangements are 1, 2, 9
        // ans = 1 + n choose 2 + 2 * n choose 3

        ll ans = 1 + n * (n - 1) / 2 + n * (n - 1) * (n - 2) / 3;

        cout << ans << endl;
    } else {

        ll ans = 1 + n * (n - 1) / 2 + n * (n - 1) * (n - 2) / 3 + 9 * n * (n - 1) * (n - 2) * (n - 3) / 24;

        cout << ans << endl;
    }



    return 0;
}
