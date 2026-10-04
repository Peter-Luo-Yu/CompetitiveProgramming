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

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        int curX = 0, curY = 0;
        vector<pair<int, int>> ans;
        while (n > 0) {
            ll val = 0;

            for (int i = 2; i <= 500; i++) {
                if ((ll) i * (ll) (i - 1) / 2LL <= n) {
                    val = i;
                }
            }

            //cout << "n: " << n << " val: " << val << endl;

            for (int i = 0; i < val; i++) {
                //cout << curX << " " << curY << endl;
                ans.push_back({curX, curY});
                curY++;
            }
            curX++;

            n -= val * (val - 1) / 2LL;
        }

        cout << ans.size() << endl;
        printP(ans);

    }


    return 0;
}
