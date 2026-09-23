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
        int n; cin >> n;
        vector<int> arr(n + 1);
        map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> arr[i + 1];
            freq[arr[i + 1]]++;   
        }

        int m = -1, Max = -1;
        
        vector<int> arr2 = arr;
        arr2.erase(arr2.begin(), arr2.begin() + 1);
        sort(arr2.begin(), arr2.end());

        m = arr2[arr2.size()/2];

        //cout << "mode: " <<  m << endl; 

        vector<int> dp (n + 1, -1e5);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            //cout << "i: " << i << endl;

            int start;
            if (i % 2 == 1) {
                start = 1;
            } else {
                start = 2;
            }

            for (int j = start; j <= i; j += 2) {
                vector<int> cur;

                for (int k = j; k <= i; k++) {
                    cur.push_back(arr[k]);
                }
                sort (cur.begin(), cur.end());

                //cout << "cur: "; print(cur);
                //cout << "median: " << cur[cur.size() / 2] << endl;

                if (cur[cur.size()/2] == m) {
                    //cout << "hmm: " << dp[j - 1] + 1 << endl;
                    dp[i] = max (dp[i], dp[j - 1] + 1);

                }
            }

            //space;
        }

        //print(dp);

        int ans = dp[dp.size() - 1];

        if (ans == 0) {
            cout << 1 << endl;
        } else {
            cout << ans << endl;
        }
        
        //space
    }
    
    return 0;
}