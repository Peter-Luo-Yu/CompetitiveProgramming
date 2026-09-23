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
        int n; cin >> n;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < n; i++) {cin >> b[i];}

        vector<int> diff (n);

        ll down = 1e18; 
        int downIdx = -1;
        bool failed = false;

        for (int i = 0; i < n; i++) {
            diff[i] = a[i] - b[i];
            if (diff[i] < 0) {
                if (down == 1e18) {
                    down = diff[i];
                    downIdx = i;
                } else {
                    failed = true;
                }

            }
        }

        down = -down;

        //cout << "down: " << down << " | "; print(diff);

        for (int i = 0; i < n; i++) {
            if (i == downIdx) continue;

            if (diff[i] < down) {
                failed = true;
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    
    return 0;
}
