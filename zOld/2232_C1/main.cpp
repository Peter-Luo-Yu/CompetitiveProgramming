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

ll n, x, s;

ll bsta(vector<char> arr, ll m) {

    ll mid = m;

    ll cnt = 0;
    ll num_tables = 0;

    ll res = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 'I') {
            if (num_tables < x) {
                num_tables++;
                res++;
            }
        }
        else if (arr[i] == 'E') {
            if (res < num_tables * s) {
                res++;
            }
        }
        else {
            if (cnt < mid) {
                if (num_tables < x) {
                    num_tables++;
                    res++;
                }
                
            } else {
                if (res < num_tables * s) {
                    res++;
                }
            }
            cnt++;
        }
    }
    //cout << res << endl;

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // main idea: let first x Ambiverts be introverts, then rest be extroverts

    int t; cin >> t;
    while (t--) {
        cin >> n >> x >> s; // x = tables, s = seats;

        string str; cin >> str;
        vector<char> arr (n);
        for (int i = 0; i < n; i++) arr[i] = str[i];

        //print(arr);

        ll l = 0, r = n;

        ll ans = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;

            ll x = bsta(arr, mid);
            ll y = bsta(arr, mid + 1);

            //cout << x << " " << y << endl;

            ans = max (x, max(y, ans));

            if (x < y) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << endl;

    }


    return 0;
}
