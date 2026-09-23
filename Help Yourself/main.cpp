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

ll MOD = 1e9 + 7;

ll pow (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--, arr[i].second--;
    }
    sort (arr.begin(), arr.end());

    vector<int> diff (2 * n), prefix (2 * n + 1);
    for (int i = 0; i < n; i++) {
        diff[arr[i].first]++;
        diff[arr[i].second]--;
    }

    //print(diff);

    for (int i = 0; i < 2 * n; i++) {
        prefix[i + 1] = prefix[i] + diff[i];
    }

    //print(prefix);

    
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll exp = n - 1 - prefix[arr[i].first];
        
        ans = (ans + pow(2LL, exp)) % MOD;
    }
    
    cout << ans << endl;

    return 0;
}
