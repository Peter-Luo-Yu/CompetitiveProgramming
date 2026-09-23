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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // y / x = k ^ n    y = k^n x 
    // log k (y / x) = log k (k ^ n)
    // log k (y) - log k (x) = n    or   logk y = logk k^n + logk x                

    int t; cin >> t;

    while (t--) {
        ll k, xMin, xMax, yMin, yMax; cin >> k >> xMin >> xMax >> yMin >> yMax;


        ll lowerX = 2e9, upperX = -1;

        for (int n = 0; n < 32; n++) {
            
            ll l = 1, r = 1e9;

            while (l <= r) {
                ll mid = (l + r)/2;
                ll val = pow (k, n) * mid;

                //cout << "l: " << l << " r: " << r << " x: " << mid << " n: " << n << " val = k^n * x: " << val << endl;

                if (val <= yMax && val >= yMin) {
                   lowerX = min(lowerX, val);  
                   r = mid - 1;      
                }
                else if (val < yMin) {
                    l = mid + 1;
                } 
                else if (val > yMax) {
                    r = mid - 1;
                } 
            }


            l = 1, r = 1e9;

            while (l <= r) {
                ll mid = (l + r)/2;
                ll val = pow (k, n) * mid;

                //cout << "l: " << l << " r: " << r << " x: " << mid << " n: " << n << " val = k^n * x: " << val << endl;

                if (val <= yMax && val >= yMin) {
                   upperX = max(upperX, val);  
                   l = mid + 1;      
                }
                else if (val < yMin) {
                    l = mid + 1;
                } 
                else if (val > yMax) {
                    r = mid - 1;
                } 
            }

        }
        cout << "lowerX : " << lowerX << " upperX: " << upperX << endl;
        

        ll ans = upperX - lowerX;
        cout << ans << endl;
    }


    return 0;
}