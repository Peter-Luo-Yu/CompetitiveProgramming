#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        ll k, d; cin >> k >> d;

        ll z = d / 2;
        if (d % 2 == 1) {
            cout << "impossible" << endl; 
            //space;
            continue;
        }

        if (k == 1) {
            cout << z << " " << 1 << endl;
            //space;
            continue;
        }
        if (k == 2) {
            // edge case: z - 1 must be greater equal to 1
            if (z - 1 >= 1) {
                cout << 1 << " " << z - 1 << endl;
            } else {
                cout << "impossible" << endl;
            }
            
            //space;
            continue;
        }

        ll n = (k + 1) / 2, nminus1 = (k) / 2;
        if (n == nminus1) {
            if (z % n == 0) {
                // edge case: res - 1 must be greater equal to 1
                ll res = z / n;
                if (res - 1 >= 1) {
                    cout << 1 << " " << res - 1 << endl;
                } else {
                    cout << "impossible" << endl;
                }
                
            } else {
                cout << "impossible" << endl;
            }
        } 
        else { // we actually have nx + (n - 1)y = z
            //cout << "n: " << n << " (n - 1): " << nminus1 << " z: " << z << endl;
            
            ll modN = z % n, modN1 = z % nminus1;
            //cout << "modN: " << modN << " modN-1: " << modN1 << endl;

            // Case 1: we subtract n - 1 's
            // subtracting (n - 1) mod n contribute +1 mod n
            
            ll y1 = n - modN, x1 = (z - nminus1 * y1) / n; 
            //cout << "x1: " << x1 << " y1: " << y1 << endl;


            // Case 2: we subtract n 's
            // subtracting n mod (n - 1) contributes -1 mod (n - 1)
            ll x2;
            if (modN1 == 0) {
                x2 = nminus1;
            } else {
                x2 = modN1;
            }

            ll y2 = (z - n * x2) / nminus1; 
            //cout << "x2: " << x2 << " y2: " << y2 << endl;

            if (x1 >= 1 && y1 >= 1) {
                cout << x1 << " " << y1 << endl;
            } 
            else if (x2 >= 1 && y2 >= 1) {
                cout << x2 << " " << y2 << endl;
            } else {
                cout << "impossible" << endl;
            }
            
        }

        //space;

    }
    
    return 0;
}
