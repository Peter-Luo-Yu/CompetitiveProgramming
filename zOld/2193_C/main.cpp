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
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n), b(n), arr(n);

        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < n; i++) {cin >> b[i];}

        for (int i = 0; i < n; i++) {
            arr[i] = max (a[i], b[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] > arr[i - 1]) {
                arr[i - 1] = arr[i];
            }
        }

        vector<int> prefix (n + 1);
        for (int i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        //cout << "arr: "; print(arr); print(prefix);

        vector<int> ans;
        //vector<pair<int, int>> query;
        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r; l--, r--;
            //query.push_back({l, r});
            int val = prefix[r + 1] - prefix[l];
            ans.push_back(val);
        }

        print(ans);

        

        

    }
    

    return 0;
}