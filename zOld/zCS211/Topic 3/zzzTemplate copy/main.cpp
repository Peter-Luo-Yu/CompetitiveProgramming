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

    ll n, m, a, c, x0; 
    cin >> n >> m >> a >> c >> x0;

    map <ll, ll> mp;
    vector<ll> arr;

    ll prev = x0;
    ll cur = (a * prev + c) % m;

    while (mp.count(cur) == 0 && arr.size() < n) {
        mp[cur]++; arr.push_back(cur);
        prev = cur; 
        cur = (a * prev + c) % m;
    }

    //print (arr);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (arr[mid] == arr[i]) {
                ans++;
                break;
            }
            else if (arr[mid] > arr[i]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
