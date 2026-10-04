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
        int n, k; cin >> n >> k;

        if (n <= k) {
            cout << n << endl;
            //space;
            continue;
        }
        

        if (n == 1) {
            cout << 1 << endl; continue;
        }
        if (n == 2) {
            if (k == 1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
            //space;
            continue;
        }
        

        int ans = 0;
        int Max = n / k;

        //cout << "Max: " << Max << endl;

        int power = 1;
        int val = (1 << power) - 1;
        while (((1 << (power + 1)) - 1) <= Max) {
            power++;
            val = (1 << power) - 1;
        }

        //cout << "val: " << val << " power: " << power << endl;

        ans += k * power;

        // leftovers

        n -= val * k;

        //cout << "left: " << n << endl;

        int addthis = n / (1 << power);

        //cout << addthis << endl;
        
        ans += addthis;

        cout << ans << endl;



        //space;

    }


    return 0;
}
