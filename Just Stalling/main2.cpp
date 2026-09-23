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

    int n;
    cin >> n;
    
    vector<int> height(n);
    vector<int> stall(n);

    for (int i = 0; i < n; i++) cin >> height[i];
    for (int i = 0; i < n; i++) cin >> stall[i];

    sort (height.begin(), height.end());
    sort (stall.begin(), stall.end());

    //print(height); print(stall);

    ll ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        int idx = lower_bound(stall.begin(), stall.end(), height[i]) - stall.begin();
        
        int poss = (n - idx) - (n - 1 - i);
        ans *= poss;
    }

    cout << ans << endl;

    return 0;
}
