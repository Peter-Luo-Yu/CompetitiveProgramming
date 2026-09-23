#include <bits/stdc++.h>
using namespace std;

// LINK: https://claude.ai/share/170673c5-c32f-476b-8ebb-06f3238af405
// I really couldn't figure this one out, but chat helped me make the observation of 
// combining the coins together and seeing if we can balance a higher denomination coin.

#define ll long long

ll mod = 1000000007;

ll power(ll x) { // computes 2^x
    ll a = 2;
    ll res = 1;
    while (x > 0) {
        if (x % 2 == 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        x = x / 2;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> arr (n);


    for (int i = 0; i < n; i++) {cin >> arr[i];}


    ll ans = 0;
    ll taped_coins = 0;


    // at each step you combine coins of lower denominations 2 at a time  
    // to convert them into the next higher denomation 

    for (int i = 0; i < n; i++) {
        // if you have an odd number of lowest denominations, and there's
        // no taped coins to pair with -> you lose one coin worth 2^i


        if (arr[i] % 2 == 1 && taped_coins == 0) { 
            ans += power(i);
        } 

        // what's intresting is that even though the number of taped_coins 
        // is odd, it's still allowed because each taped coin was formed with 
        // two coins of equal value which means you simply don't convert that 
        // final lone taped coin to the next denomination

        taped_coins = (taped_coins + arr[i])/2;
    }

    ans %= mod;

    cout << ans << endl;

    
    return 0;
}