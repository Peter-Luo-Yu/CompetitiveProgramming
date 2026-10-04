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
        int a, b; cin >> a >> b;
        a--, b--;

        __int128 ans = 1;

        int diff = a - b;
        if (diff > b) {
            swap(b, diff);
        }

        //cout << b << " " << diff << endl;

        for (int i = b + 1; i <= a; i++) {
            ans *= i;
        }

        for (int i = 1; i <= diff; i++) {
            ans /= i;
        }

        cout << (ll) ans << endl;

    }


    return 0;
}
