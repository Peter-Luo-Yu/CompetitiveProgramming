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
        int n; cin >> n;

        int ans = 10;
        for (int i = 0; i < 10; i++) {
            // adding 10^k - 1;
            int cur = n - i;

            bool success = false;

            for (int j = 0; j < 12; j++) {
                //cout << "cur: " << cur << endl;
                
                int digit = cur % 10;
                
                if (((7 - digit + 10) % 10) <= i) {
                    success = true;
                    break;
                }

                cur /= 10;
            }

            if (success) {
                cout << i << endl;
                break;
            }

            //space;
            
        }

        //cout << "==========" << endl;
    }


    return 0;
}
