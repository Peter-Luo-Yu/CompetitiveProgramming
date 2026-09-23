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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

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

        //cout << "arr:"; print(arr);

        // dp[i] len of longest inc subseq STARTING at i
        vector<int> dp (arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] < arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        

        // loop through dp table and be greedy?
        //cout << "dp: "; print(dp); 

        int cur = *max_element(dp.begin(), dp.end());
        prev = -1; int prev_idx = 0;

        vector<int> ans;

        while (cur > 0) {
            int best_val = 1e9;
            int idx = -1;

            for (int i = prev_idx; i < dp.size(); i++) {
                if (arr[i] > prev && dp[i] == cur) {
                    if (arr[i] < 1e9) {
                        best_val = arr[i];
                        idx = i;
                    }
                }
            }

            ans.push_back(arr[idx]);
            prev = arr[idx];
            prev_idx = idx + 1;
            cur--;
        }
        
        cout << ans.size() << " "; print(ans);
    }   
    
    return 0;
}
