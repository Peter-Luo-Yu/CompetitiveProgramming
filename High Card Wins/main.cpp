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

    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n; cin >> n;
    vector<int> elsie, bessie;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        elsie.push_back(val);
    }
    sort (elsie.begin(), elsie.end());


    int idx = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (i == elsie[idx]) {
            idx++;
        } else {
            bessie.push_back(i);
        }
    }

    //print(elsie); print(bessie);

    int e_idx = 0, b_idx = 0;
    int ans = 0;

    while (e_idx < n && b_idx < n) {
        if (bessie[b_idx] > elsie[e_idx]) {
            ans++;
            b_idx++; e_idx++;
        }
        else {
            b_idx++;
        }
    }

    cout << ans << endl;

    return 0;
}
