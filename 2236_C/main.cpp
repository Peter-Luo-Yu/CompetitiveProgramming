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


ll solve (ll a, ll b, ll x) {
    ll diff = abs(a - b);

    //cout << a << " " << b << endl;

    if (diff == 1) {
        return 1;
    }
    else if (diff == 0) {
        return 0;
    }

    if (a < b) swap (a, b);

    return min (diff, 1 + solve (a / x, b, x));
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        ll a, b, x; cin >> a >> b >> x;
        
        ll ans = solve(a, b, x);

        cout << ans << endl;

        //space;
    }


    return 0;
}
