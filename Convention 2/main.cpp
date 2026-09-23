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

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n; cin >> n;
    
    vector<vector<int>> arr (n);

    for (int i = 0; i < n; i++) {
        int arrive, duration;
        cin >> arrive >> duration;

        arr[i] = {arrive, n - i, duration};
    }

    sort (arr.begin(), arr.end());

    //print2d(arr);

    priority_queue<vector<int>> pq; // priority by seniority , arr time
    int idx = 0, curT = 0;
    int ans = 0;
    
    while (idx < n || !pq.empty()) {

        // arrives before the last finish time, he waits
        if (idx < n && arr[idx][0] <= curT) {
            pq.push({arr[idx][1], arr[idx][0], arr[idx][2]});
            idx++;
        }
        
        // arrives after: 2 cases
        else if (pq.empty()) { // nobody is waiting
            curT = arr[idx][0] + arr[idx][2];
            idx++;
        } else {    // somebody is waiting
            vector<int> next = pq.top(); pq.pop();
            ans = max (ans, curT - next[1]);

            curT += next[2];
        }

    }

    cout << ans << endl;

    return 0;
}
