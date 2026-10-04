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
        ll n, a, b; cin >> n >> a >> b;

        ld rate = b / 3;

        if (a <= rate) {
            ll ans = n * a;
            if (n <= 3) {
                ans = min (ans, b);
            }
            cout << ans << endl;
        }
        else {
            ll ans = min((n / 3) * b + (n % 3) * a, (n / 3) * b + (n % 3 != 0) * b);
            
            
            cout << ans << endl;
        }

        //space;
    }


    return 0;
}
