#pragma GCC optimize("O3,unroll-loops")

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
        int n, m, k; cin >> n >> m >> k;

        vector<int> robot(n), spike(m);
        for (int i = 0; i < n; i++) cin >> robot[i];
        for (int i = 0; i < m; i++) cin >> spike[i];
        string s; cin >> s;

        sort (robot.begin(), robot.end());
        sort (spike.begin(), spike.end());

        //print(robot); print(spike);

        map<int, vector<int>> dist;

        for (int i = 0; i < n; i++) {
            // first value greater than or equal to
            int ridx = lower_bound(spike.begin(), spike.end(), robot[i]) - spike.begin();
            // we can infer that lidx must be ridx - 1
            int lidx = ridx - 1;

            if (lidx >= 0) {
                dist[-abs(robot[i] - spike[lidx])].push_back(i);
            }
            if (ridx < m) {
                dist[abs(robot[i] - spike[ridx])].push_back(i);
            }
        }

        /*
        for (auto x : dist) {
            cout << x.first << " | "; print(x.second);
        }*/

        // how do you speed this up?
        // given an offset, you need to know which robots die, since each robot can only die once on the left or right O(k + 2n)
        // instead of looping through all the robots to checking their distances O(nk)
        vector<bool> vis (n);
        int alive = n;
        int offset = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'L') {
                offset--;
            } else {
                offset++;
            }

            for (auto idx : dist[offset]) {
                if (vis[idx]) continue;
                vis[idx] = true;
                alive--;
            }

            dist[offset].clear();

            cout << alive << " ";
        }
        cout << endl;

    }


    return 0;
}
