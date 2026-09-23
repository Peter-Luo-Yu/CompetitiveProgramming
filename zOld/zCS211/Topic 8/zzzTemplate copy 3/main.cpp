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

// LINK: https://chatgpt.com/share/69ade9e5-9efc-8006-bd5b-047d10df8df4 

ll mod = 1000000007;

ll power (ll x) { // computes 2 ^ x
    ll a = 2;

    ll res = 1;
    while (x > 0) {
        if (x % 2 == 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        x = x / 2;
    }

    return res;
} 


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    for (int i = 1; i < n; i++) {
        arr[i] %= 2;
    } 
    //print(arr);

    
    vector<int> cap (n);    // max sum of everything to the left

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] >= 1) {
            cap[i] = i;
        } else {
            cap[i] = cap[i - 1];
        }
    } 
    //print(cap); space

    ll ans = 0;

    for (int i = n - 1; i > 0; i--) {
        //cout << "i: " << i << " a: " << arr[i] << " c: " << cap[i] << endl;

        if (arr[i] != 1) continue;

        if (cap[i] == i && arr[0] > 1) {  // but what if arr[0] == 1
            arr[0] -= 2;
            break;
        } else {
            ans += power(i);
        }
    }

    //print(arr);

    if (arr[0] % 2 == 1) {
        ans += 1;
    }

    ans %= mod;

    cout << ans << endl;


    
    return 0;
}
