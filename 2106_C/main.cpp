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
        int n, k; cin >> n >> k;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        bool allneg = true;

        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                allneg = false;
            }
        }

        if (!allneg) {
            int sum = -1;

            for (int i = 0; i < n; i++) {
                if (b[i] != -1) {
                    sum = a[i] + b[i];
                    break;
                }
            }

            bool failed = false;

            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    int miss = sum - a[i];
                    if (miss > k || miss < 0) {
                        failed = true;
                    }
                } else {
                    if (a[i] + b[i] != sum) {
                        failed = true;
                    }
                }
            }

            if (failed) {
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
        }
        else {
            int ub = k;
            int lb = *max_element(a.begin(), a.end()) -  *min_element(a.begin(), a.end());

            int ans = max(ub - lb + 1, 0);

            cout << ans << endl;
        }

    }


    return 0;
}
