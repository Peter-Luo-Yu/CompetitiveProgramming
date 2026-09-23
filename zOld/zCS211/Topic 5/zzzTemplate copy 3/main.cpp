#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    ll l = *max_element(arr.begin(), arr.end()), r = 1e18;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;

        bool failed = false;
        int groups = 0;
        ll curW = 0;
        for (int i = 0; i < n; i++) {
            if (curW + arr[i] <= mid) {
                curW += arr[i];
            } else {
                curW = arr[i];
                groups++;
            }
        }
        if (curW > 0) {
            groups++;
        }

        //cout << "mid: " << mid << " groups: " << groups << endl;

        if (groups <= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
