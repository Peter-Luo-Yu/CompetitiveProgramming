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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ld n = 50;

    ld numer = n - (ld) 4;
    ld denom = n;

    ld ans = 1;
    for (int i = 0; i < 7; i++) {
        cout << numer << " / " << denom << endl;

        ans *= (numer / denom);
        numer--; denom--;
    }

    cout << fixed << setprecision(12) << "P(no promo): " << ans << endl;

    cout << fixed << setprecision(12) << "P(promo): " << (ld) 1 - ans << endl;


    return 0;
}
