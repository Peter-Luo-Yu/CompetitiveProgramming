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

// CHAT-GPT LINK: https://chatgpt.com/share/69acff22-9078-8006-8da9-3b095dca357c

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> price (n + 1);
    vector<int> prefix (n);
    for (int i = 0; i < n; i++) {cin >> price[i];}
    for (int i = 1; i < n; i++) {int val; cin >> val; prefix[i] = prefix[i - 1] + val;}
    prefix.push_back(1e9);


    // cost pref array
    vector<int> costs (1e6 + 5);
    int temp = 0;
    for (int i = 1; i <= 1e6; i++) {
        if (i <= prefix[temp + 1]) {
            costs[i] = costs[i - 1] + price[temp];
        } else {
            temp++;
            costs[i] = costs[i - 1] + price[temp];
        }
    }

    int d, m; cin >> d >> m;

    vector<pair<int,int>> arr (m + 1);
    arr[0] = {0, 0};
    for (int i = 1; i <= m; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    arr.push_back({d + 1, -1});

    //print(price); print(prefix); print(costs); space

    vector<int> dp (m + 2, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= m + 1; i++) {
        int cur = arr[i].first - 1; // subtract 1 because the gone day is inclusive 

        for (int j = 0; j < i; j++) {   // remember j is the starting point
            //cout << "i: " << i << " j: " << j << endl;

            int prev = arr[j].second; // don't subtract because of prefix sums stuffs

            
            int cost = costs[cur - prev] - costs[prev - prev];

            //cout << "cur: " << cur << " prev: " << prev << endl; 
            //cout << "cur: " << costs[cur] << " prev: " << costs[prev] << endl;
           
            dp[i] = min (dp[i], dp[j] + cost);

            //cout << "dp[j]: " << dp[j] << " cost: " << cost << " dp[i]: " << dp[i] << endl;

        }    

    }

    //print(dp);

    cout << dp[dp.size() - 1] << endl;

    return 0;
}
