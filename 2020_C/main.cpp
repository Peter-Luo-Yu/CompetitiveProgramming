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
    
    int t; cin >> t;
    while (t--) {
        ll b, c, d; cin >> b >> c >> d;

        ll a = 0;
        bool failed = false;
        for (int i = 0; i <= 60; i++) {
            ll mask = (1LL << i);

            ll bbit = ((b & mask) > 0), cbit = ((c & mask) > 0), dbit = ((d & mask) > 0);

            if (bbit == 0 && cbit == 0 && dbit == 0) {

            }
            else if (bbit == 0 && cbit == 1 && dbit == 0) {
                
            }
            else if (bbit == 1 && cbit == 0 && dbit == 1) {
                
            }
            else if (bbit == 1 && cbit == 1 && dbit == 1) {
                
            }
            else if (bbit == 0 && cbit == 0 && dbit == 1) {
                a += mask;
            }
            else if (bbit == 0 && cbit == 1 && dbit == 0) {
                a += mask;
            }
            else if (bbit == 1 && cbit == 0 && dbit == 1) {
                a += mask;
            }
            else if (bbit == 1 && cbit == 1 && dbit == 0) {
                a += mask;
            } else {
                failed = true;
            }
        }

        cout << (failed ? -1 : a) << endl;

    }
    


    return 0;
}
