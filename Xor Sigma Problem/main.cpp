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

    int n; cin >> n;
    vector<int> arr (n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> pref (n + 1);

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] ^ arr[i];
    }

    //print(pref);

    ll ans = 0;
    for (int i = 0; i < 31; i++) {
        ll cnt0 = 0, cnt1 = 0;

        for (int j = 0; j < pref.size(); j++) {
            if ((pref[j] & (1LL << i)) != 0) {
                cnt1++;
            } else {
                cnt0++;
            }
        }

        ans += (cnt1 * cnt0) * (1LL << i);
    }


    // apparently you overcount 
    for (int i = 0; i < n; i++) {
        ans -= arr[i];
    }

    cout << ans << endl;

    return 0;
}
