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

ll inv(ll a) {
    return pow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // the numbers can be up to 10^6
    int N = 1e6 + 5;
    vector<ll> fact(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    //print(fact);

    vector<ll> invfact(N);
    invfact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 1; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }

    //print(invfact);

    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;

        // a choose b = a! / b! (a - b)!

        ll choose = (fact[a] * invfact[b] % MOD) * invfact[a - b] % MOD;

        cout << choose << endl;
    }


    return 0;
}
