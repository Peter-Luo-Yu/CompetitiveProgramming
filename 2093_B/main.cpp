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
        string s; cin >> s;
        vector<int> arr (s.size());

        for (int i = 0; i < s.size(); i++) {
            arr[i] = s[i] - '0';
        }

        //print(arr);

        int ans = 0;
        int idx = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (arr[i] != 0) {
                idx = i;   
                break;
            } else {
                ans++;
            }
        }

        for (int i = 0; i < idx; i++) {
            if (arr[i] != 0) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
