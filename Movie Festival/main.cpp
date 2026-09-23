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

    int n; cin >> n;
    vector<pair<int, int>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort (arr.begin(), arr.end());

    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second >= t) {
            t = arr[i].first;
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
