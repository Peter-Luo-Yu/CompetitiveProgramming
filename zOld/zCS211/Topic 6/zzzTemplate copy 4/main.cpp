#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s = "-1";
    while (s != "0") {
        getline(cin, s);
        if (s == "0") {
            break;
        }

        int n = -1;
        vector<int> arr;
        int prev = -1;
        for (int i = 0; i < s.length(); i++) {
            int val;
            if (s[i] == ' ') {
                val = stoi(s.substr(prev + 1, i - prev));
                if (n == -1) {
                    n = val;
                } else {
                    arr.push_back(val);
                }
                prev = i;
            }
        }
        arr.push_back(stoi(s.substr(prev+1)));

        cout << "arr: "; print(arr);

        // dp[i] len of inc subseq ending at i, track parent of i
        vector<pair<int, int>> dp (arr.size());

        dp[0] = {1, 1e9};
        for (int i = 1; i < arr.size(); i++) {
            dp[i] = {1, 1e9};
            for (int j = 0; j < i; j++) {   // wouldn't j be the parent
                if (arr[j] < arr[i]) {
                    dp[i] = {max (dp[i].first, dp[j].first + 1), min(dp[i].second, j)};
                }
            }
        }
        
        cout << "dp: "; printP(dp);
        
        int Max = -1; 
        for (int i = 0; i < dp.size(); i++) {
            Max = max (Max, dp[i].first);
        } 

        vector<int> endpts;

        for (int i = 0; i < dp.size(); i++) {
            if (Max == dp[i].first) {
                endpts.push_back(i);
            }
        }

        cout << "endpts: "; print(endpts);
        
        vector<vector<int>> ans;

        for (int i = 0; i < endpts.size(); i++) {
            int end = endpts[i];
            vector<int> temp;
            while (end != 1e9) {
                temp.push_back(arr[end]);
                end = dp[end].second;
            }
            reverse (temp.begin(), temp.end());
            ans.push_back(temp);

        }
        
        cout << "poss: "; print2d(ans);
        sort (ans.begin(), ans.end());


        cout << Max << " "; print(ans[0]); 
        
        cout << "-----" << endl;
    }
    
    return 0;
}
