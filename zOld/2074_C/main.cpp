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
        int x; cin >> x;

        int ans = -1;

        for (int i = 0; i < 32; i++) { // must share this bit 

            //cout << "i: " << i << endl;

            for (int j = 0; j < 32; j++) { // must not share this bit
                if (i == j) continue;
                if ((x & (1 << i)) <= 0) continue;

                ll cur = 1 << i;

                if ((x & (1 << j)) > 0) {
                    cur -= (1 << j);
                } else {
                    cur += (1 << j);
                }
                
                //cout << "j: " << j << " cur: " << cur << endl;

                if (cur >= x) continue;

                if ((x + cur > (x ^ cur)) && (x - cur < (x ^ cur))) {
                    ans = cur;
                    break;
                }
            }

            if (ans != -1) {
                break;
            }
        }

        cout << ans << endl;

    }


    return 0;
}
