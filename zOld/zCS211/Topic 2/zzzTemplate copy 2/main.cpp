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
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; i++) {cin >> a[i];}
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {cin >> b[i];}
    
    map<int, int> mp;      // a is 0, b is 1, a and b is 2
    for (int i = 0; i < a.size(); i++) {
        mp[a[i]] = 0;
    }
    for (int i = 0; i < b.size(); i++) {
        if (mp.count(b[i]) > 0) {
            mp[b[i]] = 2;
        } else {
            mp[b[i]] = 1;
        }
    }

    bool one = true;
    bool two = true;
    int ans = 0;
    for (auto x : mp) {
        if (x.second == 0 && two == true) {    // watching a's movie
            one = true;
            two = false;
            ans++;
        } else if (x.second == 1 && one == true) {
            one = false;
            two = true;
            ans++;
        } else if (x.second == 2) {
            one = true;
            two = true;
            ans++;
        } 
    } 
    cout << ans << endl;
    return 0;
}