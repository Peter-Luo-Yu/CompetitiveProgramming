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

    vector<ll> arr (50);
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    ll sum = 6;
    for (int i = 3; i < 50; i++) {
        arr[i] = sum;
        sum *= 2;
    }
    //print(arr);

    
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        if (n == 2) {
            cout << -1 << endl;
            continue;
        }
    
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            cout << arr[i] << " ";
        }
        cout << endl;

        /*
        bool failed = false;
        for (int i = 0; i < n; i++) {
            if (sum % arr[i] != 0) {
                cout << "f: " << arr[i] << endl;
            }
        }
        */
    }



    return 0;
}
