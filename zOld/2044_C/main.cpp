#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // m seats per row, a perfer r1, b prefer r2, 

    int t; cin >> t;
    while (t--) {
        int m, a, b, c; cin >> m >> a >> b >> c;

        int ans = 0;

        int r1 = min (m, a);
        int r2 = min (m, b);

        int leftover = 2 * m - r1 - r2;

        int rest = min (leftover, c);

        ans = r1 + r2 + rest;

        cout << ans << endl;

    }
    

    return 0;
}