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
        int n, m, k; cin >> n >> m >> k;

        vector<int> arr (n + m);

        int x = max (n, m), y = min (n, m);
        int zero, one; 
        if (n == x) {
            zero = 0, one = 1;
        } else {
            zero = 1, one = 0;
        }
        
        if (k < x - y || k > x) {
            cout << -1 << endl;
            continue;
        }

        int xcnt = x, ycnt = y;
        for (int i = 0; i < k; i++) {
            cout << zero;
            xcnt--;
        } 
        
        while (ycnt > 0) {
            cout << one; ycnt--;

            if (xcnt > 0) {
                cout << zero;
                xcnt--;
            }
        }
        cout << endl;

        //space;

    }
    
    return 0;
}
