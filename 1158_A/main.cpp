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

    ll n, m; cin >> n >> m;
    vector<ll> boys(n), girls(m);
    for (int i = 0; i < n; i++) cin >> boys[i];
    for (int i = 0; i < m; i++) cin >> girls[i];

    sort (boys.begin(), boys.end()); 
    sort (girls.begin(), girls.end()); 

    //print(boys); print(girls);

    if (boys[n - 1] > girls[0]) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < boys.size(); i++) {
        ans += boys[i] * m;
    }

    // even the fattest boy is skinnier than the skinniest girl
    // let the biggest guy satisfy all the girls 
    for (int i = 1; i < m; i++) {
        ans += girls[i] - boys[n - 1];
    }

    // he still has to satisfy himself, if he can't, then let the second fattest guy do it to the last girl
    if (boys[n - 1] != girls[0]) {
        ans += girls[0] - boys[n - 2];
    }
    
    
    cout << ans << endl;


    return 0;
}
