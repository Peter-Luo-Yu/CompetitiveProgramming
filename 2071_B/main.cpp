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
        ll n; cin >> n;

        ll sum = (n * (n + 1))/2LL;
        ll root = sqrt (sum);
        if (root * root == sum) {
            cout << -1 << endl;
            continue;
        }

        ll cur = 0;
        bool flipped = false;
        for (int i = 1; i <= n; i++) {
            cur += i;

            if (!flipped) {
                root = sqrt(cur);
                if (root * root == cur) {
                    cout << i + 1 << " ";
                    flipped = true;
                } else {
                    cout << i << " ";
                }
            } else {
                cout << i - 1 << " "; 
                flipped = false;
            }
            
        }
        cout << endl;
    }
    


    return 0;
}
