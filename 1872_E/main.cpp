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
        vector<int> arr(n), pref(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            pref[i + 1] = pref[i] ^ arr[i];
        }
        string s; cin >> s;

        int g0 = 0, g1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                g0 ^= arr[i];
            } else {
                g1 ^= arr[i];
            }
        }
        
        //cout << g0 << " " << g1 << endl;

        int m; cin >> m;
        while (m--) {
            int type;
            cin >> type;

            if (type == 2) {
                int group; 
                cin >> group;
                if (group == 0) {
                    cout << g0 << " ";
                } else {
                    cout << g1 << " ";
                }
            } else {
                int l, r;
                cin >> l >> r;
                
                g0 ^= (pref[r] ^ pref[l - 1]);
                g1 ^= (pref[r] ^ pref[l - 1]);
            }
        }

        cout << endl;
    }


    return 0;
}
