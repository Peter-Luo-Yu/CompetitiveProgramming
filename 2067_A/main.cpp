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
        int x, y; cin >> x >> y;

        if (x == y) {
            cout << "NO" << endl;
        }
        else if (y > x) {
            if (x + 1 == y) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            int num9 = x / 9;
            int maxDecrease = (num9 - 1) * 9 + 8;

            //cout << " " << maxDecrease << endl;

            if (maxDecrease < x - y) {
                cout << "NO" << endl;
                continue;
            } 

            int diff = x - y;
            if ((diff - 8) % 9 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }


    return 0;
}
