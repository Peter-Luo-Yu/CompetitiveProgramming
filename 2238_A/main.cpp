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
        int n, c; cin >> n >> c;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        bool swap = false;
        int noswap = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                swap = true;
            }
            else {
                noswap += a[i] - b[i];
            }
        }

        int yesswap = c;
        bool failed = false;
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                failed = true;
            }
            else {
                yesswap += a[i] - b[i];
            }
        }

        if (failed) {
            cout << -1 << endl;
        } else {
            int ans = yesswap;
            if (!swap) {
                ans = min (ans, noswap);
            }
            cout << ans << endl;
        }


        //space;
    }


    return 0;
}
