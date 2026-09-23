#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        ll ans = 0;
        int maxLoser = -1e9;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[i]) {
                ans += a[i];
                maxLoser = max (maxLoser, b[i]);
            } else if (a[i] < b[i]) {
                ans += b[i];
                maxLoser = max (maxLoser, a[i]);
            } 
        }

        ans += maxLoser;

        cout << ans << endl;

    }
    

    return 0;
}