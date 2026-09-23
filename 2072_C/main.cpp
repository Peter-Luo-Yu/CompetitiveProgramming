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
        int n, x;
        cin >> n >> x;

        int or_val = 0;
        vector<int> ans (n);

        for (int i = 0; i <= min(n - 1, x); i++) {
            if (((or_val | i) & x) == (or_val | i)) { // checking every bit set in the next or_val must be also set in x;
                ans[i] = i;
                or_val |= i;
            }
        }
        
        //print(ans);
        //cout << or_val << endl;

        if (or_val != x) {
            ans[n - 1] = x;
        }

        print(ans);
    }
    


    return 0;
}
