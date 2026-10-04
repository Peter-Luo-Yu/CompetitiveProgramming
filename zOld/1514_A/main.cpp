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

    // perfect square is always prime ^ even power
    // multiplying two perfect squares -> results in perfect square
    // ex 4 * 9 = 36, because you keep the fact that (prime ^ even power) * (p ^ even) = p ^ even
    // because even + even = even.

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        bool allsquare = true;
        for (int i = 0; i < n; i++) {
            int val = arr[i];

            bool square = false;
            for (int j = 1; j * j <= val; j++) {
                if (j * j == val) {
                    square = true;
                }
            }

            if (!square) {
                allsquare = false;
            }

        }

        if (allsquare) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }



    return 0;
}
