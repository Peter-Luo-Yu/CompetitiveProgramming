#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a (n);
        for (int i = 0; i < n; i++) cin >> a[i];


        int ans = -1;
        if (k == n) {
            vector<int> temp;
            for (int i = 1; i < n; i+=2) {
                temp.push_back(a[i]);
            }
            temp.push_back(0);
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == i + 1) {
                    continue;
                } else {
                    ans = i + 1;
                    break;
                }
            }
        } else {
            // want 2nd subarray to not start with 1
            // ranges: 2 -> n - k + 2

            for (int i = 1; i <= n - k + 1; i++) {
                if (a[i] != 1) {
                    ans = 1;
                    break;
                }
            }
            if (ans == -1) {
                ans = 2;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
