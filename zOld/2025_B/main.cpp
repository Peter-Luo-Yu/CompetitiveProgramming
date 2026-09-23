#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

const ll MOD = 1e9 + 7;

ll bin_exp (ll a, ll b){
    ll res = 1;
    a %= MOD;

    while (b > 0){
        if (b % 2 == 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
        
    }
    return res; 

}

int main() {
    /*
    int N = 1000;
    vector<vector<ll>> C (N, vector<ll> (N));

    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++){ // loop over k from 1 to n-1 (inclusive)
            C[n][k] = (C[n][k-1] + C[n - 1][k - 1]) % 1000000007;
        }
    }*/

    // the answer is 2^k[i] % 10^9 + 7

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t; 
    
    vector<ll> n (t), k (t);

    for (int i = 0; i < t; i++){
        cin >> n[i];
    }
    for (int i = 0; i < t; i++){
        cin >> k[i];
    }

    //print(n); print(k);

    for (int i = 0; i < t; i++){
        cout << bin_exp(2, k[i]) << endl;
    }
   
    

    return 0;
}