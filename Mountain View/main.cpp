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

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
 
    ll n; cin >> n;
    vector<vector<ll>> arr;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;

        arr.push_back({a - b, a + b, i});
    }

    sort (arr.begin(), arr.end());

    //print2d(arr);

    ll cnt = 0;
    ll l = 0, r = 0; 
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            //l = arr[i][0];
            r = arr[i][1];
            cnt++;
            continue;
        }
       
        if (arr[i][1] > r) {
            cnt++;
            r = arr[i][1];
        }
        
    }

    cout << cnt << endl;
    
    return 0;
}
