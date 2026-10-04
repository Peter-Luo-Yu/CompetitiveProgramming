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

ll solve (ll a, ll b) {
    if (a == b){
        return 0;
    }
    else if (a > b) {
        ll is_odd = a % 2;
        return 1 + is_odd + solve ((a + is_odd) / 2, b);
    } else {
        ll is_odd = b % 2;
        return min (b - a, 1 + is_odd + solve(a, (b - is_odd)/2));
    }

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
    }

    return 0;
}
