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

    ll n; cin >> n;
    vector<ll> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort (arr.begin(), arr.end());

    ll a = arr[n / 2], b = arr[n/2 - 1];
    //cout << a << " " << b << endl;

    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        ans1 += abs(a - arr[i]);
        ans2 += abs(b - arr[i]);
    }

    cout << min (ans1, ans2) << endl;

    return 0;
}
