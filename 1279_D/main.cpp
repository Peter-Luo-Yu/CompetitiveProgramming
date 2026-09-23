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

ll MOD = 998244353;

ll power (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;

        b /= 2;
    }
    return res;
} 

ll inverse (ll a) {
    return power(a, MOD - 2);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);    

    map<int, int> freq; // how many kids want gift y: y - cnt
    
    int n; cin >> n;
    vector<vector<int>> arr (n);

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        vector<int> temp (k);

        for (int j = 0; j < k; j++) {
            int gift; cin >> gift;
            freq[gift]++;
            temp[j] = gift;
        }

        arr[i] = temp;
    }

    //print2d(arr);

    ll ans = 0;
    // goal: (1/n^2) summation each kid [(1/k) sum each gift [freq of gift]]
    
    for (int i = 0; i < n; i++) {
        ll temp = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            temp += freq[arr[i][j]];
        }
        temp %= MOD;
        temp *= inverse(arr[i].size());
        temp %= MOD;

        ans += temp;
        ans %= MOD;
    }

    ll nsquared = (1LL * n * n) % MOD;
    ans *= inverse(nsquared);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}
