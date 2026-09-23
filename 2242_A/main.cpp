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
        vector<int> arr (n);
        for (int i = 0;  i< n; i++) cin >> arr[i];

        bool good = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 3) {
                good = true;
            }
        }

        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++) {
            if (idx1 == -1) {
                if (arr[i] >= 2) {
                    idx1 = i;
                }
            }
            if (arr[i] >= 2) {
                idx2 = i;
            }
        }

        if (idx1 != idx2) {
            good = true;
        }

        cout << (good ? "YES" : "NO") << endl;
    }


    return 0;
}
