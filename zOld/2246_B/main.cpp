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

ll binpow (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res *= a;
        } 
        a *= a;
        b /= 2;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N = 100;

    vector<ll> div (100);
    for (int i = 0; i < N; i++) {
        div[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += 2) {
            if (div[j] == j) {
                div[j] = i;
            }
        }
    }

    //print(div);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        // prime factor - max val;
        map<ll, ll> mp; 

        for (int i = 1; i <= n; i++) {
            ll val = i;
            while (val > 1) {
                ll p = div[val];
                ll exp = 0;
                while (val % p == 0) {
                    val /= p;
                    exp++;
                }

                mp[p] = max (mp[p], exp);
            }
        }

        //printP(mp);

        ll sum = 1;

        for (auto x : mp) {
            sum *= binpow(x.first, x.second);
        }

        //cout << sum << endl;

        for (int i = 0; i < n - 1; i++) {
            cout << i + 1<< " ";
            sum -= (i + 1);
        }
        cout << sum << endl;

        //space;
    }



    return 0;
}
