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

    string s; cin >> s;

    vector<int> cnt (10);
    map<vector<int>, ll> mp;
    
    mp[cnt]++;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - '0'] += 1;
        cnt[s[i] - '0'] %= 2;
        mp[cnt]++;
    }

    ll ans = 0;

    for (auto m : mp) {
        ll x = m.second;
        ans += (x * (x - 1)) / 2;
    }

    cout << ans << endl;

    return 0;
}
