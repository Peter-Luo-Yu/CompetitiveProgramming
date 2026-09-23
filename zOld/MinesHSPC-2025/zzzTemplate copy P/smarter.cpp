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
            
            ll y = (n - (z % n)) % n;
            if (y == 0) {
                y = n;
            }

            ll remain = z - y * nminus1;

            if (remain > 0 && remain % n == 0) {
                ll x = remain / n;
                if (x >= 1) {
                    cout << x << " " << y << endl;
                }
                else {
                    cout << "impossible" << endl;
                }

            } else {
                cout << "impossible" << endl;
            }
            
        }

        //space;

    }
    
    return 0;
}
