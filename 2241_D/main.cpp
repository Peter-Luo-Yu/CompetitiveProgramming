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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll cost = 0;

        for (int i = n - 1; i > 0; i--) {
            if (a[i] > b[i]) {
                cost += a[i] - b[i];
            }
            if (a[i] < b[i]) {
                cost -= min (cost, b[i] - a[i]);
            }
        }

        //cout << cost << endl;

        a[0] += cost;

        /*
        bool less = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                less = false;
            }
        }

        if (cost == 0 && less) {
            a[0] = b[0];
        } */
    
        if (a[0] > b[0]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        
    }


    return 0;
}
