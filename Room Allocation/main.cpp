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

    int n; cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b, i});
    }
    sort (arr.begin(), arr.end());
    
    //print2d(arr);

    int cnt = 0;
    int id = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans (n);

    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            pq.push({arr[i][1], id}); 
            ans[arr[i][2]] = id;

            id++;
            cnt++;
        } 
        else {
            if (pq.top().first < arr[i][0]) {
                int cur_id = pq.top().second;
                pq.pop();
                pq.push({arr[i][1], cur_id});
                ans[arr[i][2]] = cur_id;

            } else {
                pq.push({arr[i][1], id}); 
                ans[arr[i][2]] = id;

                id++;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    print(ans);

    return 0;
}
