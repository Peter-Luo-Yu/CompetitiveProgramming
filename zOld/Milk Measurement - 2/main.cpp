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

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g; cin >> n >> g;
    map<int, int> arr;
    map<int, int> freq;

    freq[g] = n;

    vector<vector<int>> log (n);
    for (int i = 0; i < n; i++) {
        int day, cow, amt;
        cin >> day >> cow >> amt;
        log[i] = {day, cow, amt};

        arr[cow] = g;
    }

    sort (log.begin(), log.end());

    //print2d(log);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cow = log[i][1]; // cow idx

        // save prev info
        int prev_amt = arr[cow];
        int prev_cnt = freq[prev_amt];
        int prev_max = freq.rbegin() -> first;

        bool was_leader = prev_amt == prev_max;

        // update
        freq[prev_amt]--;
        if (freq[prev_amt] == 0) freq.erase(prev_amt);

        int cur_amt = prev_amt + log[i][2];
        arr[cow] = cur_amt;
        freq[cur_amt]++;

        // save cur info
        int cur_cnt = freq[cur_amt];
        int cur_max = freq.rbegin() -> first;
        bool is_leader = cur_amt == cur_max;

        //cout << "prev amt: " << prev_amt << " cnt: " << freq[prev_amt] << " max: " << prev_max << endl;
        //cout << "cur amt: " << cur_amt << " cnt: " << freq[cur_amt] << " max: " << cur_max << endl;

        // got promoted or demoted = change
        if ((!was_leader && is_leader) || (was_leader && !is_leader)) {
            ans++;
        }
        else if (was_leader && is_leader) {
            // he could have been the sole leader before, and is still the sole leader now
            // means no change in picture, unless the cnts are different (no longer sole leader)
            if (prev_cnt != cur_cnt) {
                ans++;
            }
        } 
        else {
            // do nothing if he wasn't the leader before and isn't the leader now
        }       

        //space;
    }

    cout << ans << endl;

    return 0;
}
