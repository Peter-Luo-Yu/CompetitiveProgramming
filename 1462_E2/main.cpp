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

int N = 1e6;
vector<ll> fact(N), invfact(N);

ll pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

ll nCr (ll n, ll r) {
    if (r < 0 || r > n) return 0;

    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
} 


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fact[0] = 1; invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = pow(fact[i], MOD - 2);
    }

    //print(fact); print(invfact);

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort (arr.begin(), arr.end());

        // fix the lower bound of len k interval, answer is 
        // cnt choose m - 1
        
        ll ans = 0;

        //print(arr);

        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin();

            //cout << l << " " << r << endl;

            ans = (ans + nCr(r - l, m - 1)) % MOD;
        }

        cout << ans << endl;
        
    }


    return 0;
}
