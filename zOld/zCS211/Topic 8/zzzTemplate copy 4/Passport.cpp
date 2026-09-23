#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lll __int128_t
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

// AI: https://gemini.google.com/share/f02ae8a2d809
// I got juked on this problem, because I was trying to divide the array into 2 parts everytime.
// AI helped me realize that when you have n blocks, you want to divide it up into n + 1 parts.
// and there's a clever way to use math to track how many spaces have been taken.

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, p; cin >> n >> p;


    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;

        if (i == 0 && p < val) {
            cout << 0 << endl;
            return 0;
        }

        // strat: instead of trying to break up the gaps by 2 everytime -> which fails
        // we need to block up lengths of val - 1 at each i.
        // at each i, there are currently i + 1 gaps (not i + 2, until you place this block)
        // blocked = i + 1 * val - 1

        // you are trying to place block i
        // so don't increment the sum yet.

        lll blocked = (lll) (i + 1) * (val - 1);

        if (p - sum <= blocked) {
            break;
        } else {
            sum += val;
            ans++;
        }

        
    }

    cout << ans << endl;
    
    return 0;
}