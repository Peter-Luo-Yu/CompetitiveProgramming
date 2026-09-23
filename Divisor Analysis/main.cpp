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
 
ll power (ll a, ll b) {
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

ll inverse (ll a) {
    return power(a, MOD - 2);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    ll num = 1, sum = 1, prod = 1;

    ll num_exp = 1; // num divisors mod - 1

    for (int i = 0; i < n; i++) {
        ll factor, exp; cin >> factor >> exp;

        num = num * (exp + 1) % MOD;
        
        ll numerator = (power(factor, exp + 1) - 1 + MOD) % MOD;
        ll denominator = inverse(factor - 1);
        sum = (sum * (numerator * denominator % MOD)) % MOD;


        prod = power(prod, exp + 1) * 
               power(factor, ((exp * (exp + 1) / 2) % (MOD - 1)) * num_exp) % MOD;

        num_exp = (num_exp * (exp + 1)) % (MOD - 1);
        
    }

    cout << num << " " << sum << " " << prod << endl;
    
    return 0;
}
