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

    int n, m; cin >> n >> m;
    vector<string> sgr (n);
    for (int i = 0; i < n; i++) {
        cin >> sgr[i];
    }

    while (m--) {
        string s; cin >> s;

        vector<int> dp(s.size() + 1);
        dp[0] = 1;

        map<int, vector<int>> seq;

        for (int i = 1; i <= s.size(); i++) { // this is the ending point

            for (int j = 0; j < sgr.size(); j++) {
                int length = sgr[j].size();
                if (i - length < 0) continue;

                // we are replacing sub with sgr
                //cout << sgr[j] << " " << length << endl;

                string sub = s.substr(i - length, length);
                //cout << sub << endl;

                if (dp[i - length] == 1 && sgr[j] == sub) {
                    dp[i] = 1;

                    seq[i] = seq[i - length];
                    seq[i].push_back(j);
                }
            }
        }
        
        /*
        print(dp);
        for (auto s : seq) {
            cout << s.first << " | "; print(s.second);
        }
        */

        if (dp[s.size()] == 1) {
            for (auto i : seq[s.size()]) {
                cout << i + 1 << " ";
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }


        //cout << "==========" << endl;
    }


    return 0;
}
