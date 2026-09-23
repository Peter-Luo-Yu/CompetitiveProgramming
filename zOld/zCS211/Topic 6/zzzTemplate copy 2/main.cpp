#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

map<ll, vector<ll>> arr;
map<ll, string> res;
map<ll, ll> dp;

ll recurse (ll n) {
    if (dp.count(n)) return dp[n];


    if (res.count(n) > 0 && res[n] == "favourably") {
        dp[n] = 1;
        return dp[n];
    } else if (res.count(n) > 0 && res[n] == "catastrophically") { 
        dp[n] = 0;
        return dp[n];
    }

    ll ans = 0;

    for (int i = 0; i < arr[n].size(); i++) {
        //cout << "arr:" << arr[n][i] << endl;
        ans += recurse (arr[n][i]);
    }

    dp[n] = ans;
    return dp[n];
}

int main () {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        arr.clear();
        res.clear();
        dp.clear();

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            ll a, c, d;
            string b;
            cin >> a >> b;

            if (b != "favourably" && b != "catastrophically") {
                cin >> c >> d;
                arr[a] = {stoll(b), c, d};
            } else {
                res[a] = b;
            }
        }

        /*
        for (auto x : arr) {
            cout << x.first << " "; print(x.second);
        }
        for (auto x : res) {
            cout << x.first << " " << x.second << endl;
        } */

        cout << recurse (1) << endl;
    }


    return 0;
}