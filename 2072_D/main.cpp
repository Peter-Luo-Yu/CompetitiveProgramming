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

        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans_l = 1, ans_r = 1, best = 0;

        for (int l = 0; l < n; l++) {
            int cur = 0;

            for (int r = l + 1; r < n; r++) {
                if (arr[l] < arr[r]) cur++; // after swap arr[l] > arr[r] => inversion
                else if (arr[l] > arr[r]) cur--;

                if (cur < best) {
                    best = cur;
                    ans_l = l + 1;
                    ans_r = r + 1;
                }
            }
        }

        cout << ans_l << " " << ans_r << endl;
    }


    return 0;
}
