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
        int n, x, y, z; cin >> n >> x >> y >> z;

        // z hours to set up
        // t (x + y) vs z * x + (t - z) (x + 10y)

        int nosetup = 0;
        int setup = 0;

        int ans = 1e9;
        for (int i = 1; i < 10000; i++) {
            nosetup += (x + y);

            if (i <= z) {
                setup += x;
            } else {
                setup += x + 10*y;
            }

            if (setup >= n) {
                ans = min (ans, i);
            } 
            if (nosetup >= n) {
                ans = min (ans, i);
            }
        }   

        cout << ans << endl;
    }


    return 0;
}
