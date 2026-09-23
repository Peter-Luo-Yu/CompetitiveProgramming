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

    int n, c; cin >> n >> c;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        arr.push_back({b, a});
    }
    
    sort (arr.begin(), arr.end());

    //printP(arr);

    int cost = 0, ans = 0;
    vector<bool> vis (24);

    for (int i = 0; i < arr.size(); i++) {
        if (!vis[arr[i].second] && cost + arr[i].first <= c) {
            vis[arr[i].second] = true;
            cost += arr[i].first;
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}
