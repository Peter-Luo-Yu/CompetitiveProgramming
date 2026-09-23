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

    int n, m, q; cin >> n >> m >> q;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // find wu for every possible string 1 -> 4096
    vector<int> wu (1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // if jth bit is on, then we add to wu
                wu[i] += arr[j];
            }
        }
    }

    vector<int> string_cnt (1 << n);
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        int val = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') {
                val += 1 << j;
            }
        }
        string_cnt[val]++;
    }

    vector<vector<int>> pref (1 << n, vector<int> (101));
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {

            int same = ~(i ^ j);
            int mask = (1 << n) - 1;

            int wu_val = wu[same & mask];
            if (wu_val <= 101) {
                pref[i][wu_val] += string_cnt[j];
            }

        }

        for (int j = 0; j < 101; j++) {
            pref[i][j + 1] = pref[i][j + 1] + pref[i][j];
        }
    }

    while (q--) {
        string t; int k;
        cin >> t >> k;
        int val = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '1') {
                val += (1 << i);
            }
        }

        cout << pref[val][k] << endl;
    }

    return 0;
}
