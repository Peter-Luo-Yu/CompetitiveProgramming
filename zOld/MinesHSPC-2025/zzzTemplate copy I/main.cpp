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

    int n; cin >> n;
    vector<int> x(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> a[i] >> b[i];
    }

    vector<pair<ld, int>> slopes;

    for (int i = 0; i < n; i++) {
        slopes.push_back({(ld) a[i]/ (ld) x[i], 0});
        slopes.push_back({(ld) b[i]/ (ld) x[i], 1});
    }
   
    sort (slopes.begin(), slopes.end());

    //printP(slopes);

    int ans = 0;
    int cur = 0;


    // running sum - difference array problem

    for (int i = 0; i < slopes.size(); i++) {
        if (slopes[i].second == 0) {
            cur++;
        } else {
            cur--;
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
