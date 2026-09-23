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

        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        sort (arr.begin(), arr.end());

        vector<int> l, r;

        int amt = n - k;
        for (int i = 0; i < amt; i++) {
            l.push_back(arr[i]);
        }
        for (int i = n - 1; i > n - 1 - amt; i--) {
            r.push_back(arr[i]);
        }
        reverse(r.begin(), r.end());

        //print(l); print(r);

        int lb, rb;
        if (amt % 2 == 0) {
            lb = l[l.size() / 2 - 1];
            rb = r[r.size() / 2];
        } else {
            lb = l[l.size() / 2];
            rb = r[r.size() / 2];
        }

        cout << rb - lb + 1 << endl;
    }


    return 0;
}
