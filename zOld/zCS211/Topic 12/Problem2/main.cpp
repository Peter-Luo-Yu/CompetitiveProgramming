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
        ll a, y; cin >> a >> y;

        vector<ll> arr (a);
        for (int i = 0; i < a; i++) {
            cin >> arr[i];
        }


        set<ll> dp;
        dp.insert(1);

        for (int i = 0; i < arr.size(); i++) {
            vector<ll> newvals;
            
            for (auto val : dp) {
                ll newval = val * arr[i];  

                if (newval <= y) {
                    newvals.push_back(newval);
                }
            }

            for (int i = 0; i < newvals.size(); i++) {
                dp.insert(newvals[i]);
            }
        }

        //print(dp);

        ll ans = -1;
        for (auto val : dp) {
            if (val <= y) {
                ans = max(ans, val);
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
