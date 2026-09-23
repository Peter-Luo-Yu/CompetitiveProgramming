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
        vector<ll> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll ans = 1e18;

        for (int k = 0; k < 31; k++) {
            ll power = (1LL << k);
            ll kcost = 0;

            for (int i = 0; i < n; i++) {
                // smallest multiple >= arr[i]
                ll small = ((arr[i] / power) + (arr[i] % power != 0)) * power; 
                ll diff = small - arr[i];
                ll minCost = small - arr[i] + __builtin_popcountll(small) + (63 - __builtin_clzll(small)); // best cost for current element

                if (diff <= 60) {
                    for (ll goal = small; goal - arr[i] < 60; goal += power) {
                        ll promocost = goal - arr[i];

                        ll cost = promocost + __builtin_popcountll(goal) + (63 - __builtin_clzll(goal));
                        minCost = min(cost, minCost);
                    }
                }

                kcost += minCost;
            }

            ll finalcost = kcost - (n - 1) * k; // reductions, becuase you can divide k times
            ans = min(ans, finalcost);
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
