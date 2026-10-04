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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    // stars and bars, n kids, m apples
    // n + m - 1 choose n - 1
    // ex. 3 kids 2 apples, ans = 4 choose 2 = 6

    int N = 2 * 1e6 + 5; 

    vector<ll> fact (N), invfact(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[N - 1] = pow(fact[N - 1], MOD - 2);
    for (int i = N - 1; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }

    //print(fact); print(invfact);

    ll ans = (fact[n + m - 1] * invfact[n - 1] % MOD) * invfact[m] % MOD;

    cout << ans << endl;


    return 0;
}
