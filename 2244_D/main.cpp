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
        int n, m; cin >> n >> m;
        vector<int> arr1(n), arr2(n);
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
            arr2[i] = arr1[i] * (-1);
        }
        
        vector<ll> pref1(n + 1), pref2(n + 1);
        for (int i = 0; i < n; i++) {
            pref1[i + 1] = pref1[i] + arr1[i];
            pref2[i + 1] = pref2[i] + arr2[i];
        }

        //print(pref1); print(pref2);

        vector<int> order (m);
        for (int i = 0; i < m; i++) cin >> order[i];
        sort(order.begin(), order.end(), greater<int> ());
        order.push_back(0);

        ll ans = 0;
        for (int i = 0; i < m; i++) {
            int idx1 = order[i], idx2 = order[i + 1];
            ans += max(pref1[idx1] - pref1[idx2], pref2[idx1] - pref2[idx2]);
        }

        ans += pref1[n] - pref1[order[0]];

        cout << ans << endl;

        //space;
    }
    


    return 0;
}
