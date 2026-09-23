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
        vector<int> arr (n);
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            arr[i] = s[i] - '0';
        }

        for (int i = 0; i < n - k; i++) {
            if (arr[i] == 1) {
                arr[i] = 0;
                
                if (arr[i + k] == 0) {
                    arr[i + k] = 1;
                } else {
                    arr[i + k] = 0;
                }
                
            }
        }

        //print(arr);

        bool failed = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                failed = true;
            }
        }

        cout << (failed ? "NO" : "YES") << endl;
    }


    return 0;
}
