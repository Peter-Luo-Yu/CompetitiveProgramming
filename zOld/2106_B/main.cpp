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
        int n, x; cin >> n >> x;

        int ops = 0;
        for (int i = 0; i < x; i++) {
            cout << i << " ";
            ops++;
        }

        if (ops == n) {
            cout << endl;
            continue;
        }
        //cout << "ops: " << ops << " 2: " << n - ops - 1 << endl;

        int val = x + 1;
        for (int i = 0; i < n - ops - 1; i++) {
            cout << val << " ";
            val++;
        }

        
        cout << x << endl;
        

        //space;
    }
    


    return 0;
}
