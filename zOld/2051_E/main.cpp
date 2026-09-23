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
 
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
 
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < n; i++) {cin >> b[i];}
 
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
 
        //print(a); print(b);
 
        ll earn = -1;
        
        // the price is a[i]
        for (int i = 0; i < a.size(); i++) {
            ll buys = 0;
            ll curK = 0;

            // number of buys, price <= b
            ll idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            ll idx2 = lower_bound(a.begin(), a.end(), a[i]) - a.begin();
            
            
            buys += b.size() - idx;

            ll happy = n - idx2;
            curK = buys - happy;
 
            //cout << "price: " << a[i] << " bought starting at: " << idx  << " happy: " << n - idx2;
            //cout << " buys: " << buys << " k: " << curK << endl;
 
            if (curK <= k) {
                earn = max(earn, a[i] * buys);
            }
        }
 
        for (int i = 0; i < b.size(); i++) {
            ll buys = 0;
            ll curK = 0;
 
            ll idx = lower_bound(b.begin(), b.end(), b[i]) - b.begin();
            ll idx2 = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
            
            buys += b.size() - idx;
            ll happy = n - idx2;
            curK = buys - happy;
 
            //cout << "price: " << b[i] << " bought starting at: " << idx  << " happy: " << n - idx2;
            //cout << " buys: " << buys << " k: " << curK << endl;
 
            if (curK <= k) {
                earn = max(earn, b[i] * buys);
            }
        }
        
        cout << earn << endl;
        //cout << "----" << endl;
    }
    
    return 0;
}