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

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<pair<int, int>> cows (m);
    for (int i = 0; i < m; i++) cin >> cows[i].first >> cows[i].second;

    sort (arr.begin(), arr.end());
    sort (cows.begin(), cows.end());

    //print(arr);
    //printP(cows);

    int ans = 0;
    
    int cow_idx = 0;

    // for each chicken, we need a know which cows are available
    // we select the cow with earliest ending time

    priority_queue<int, vector<int>, greater<int>> pq; 
    for (int i = 0; i < n; i++) {

        while (cow_idx < m && cows[cow_idx].first <= arr[i]) {
            pq.push(cows[cow_idx].second);
            cow_idx++;
        }

        while (!pq.empty() && pq.top() < arr[i]) {
            pq.pop();
        }

        if (!pq.empty()) {
            ans++;
            pq.pop();
        }

    }

    cout << ans << endl;

    return 0;
}
