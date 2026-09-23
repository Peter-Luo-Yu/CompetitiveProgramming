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
        int n, k; cin >> n >> k;
        vector<char> s (n);
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) cin >> arr[i];

        //print(s);
        //print(arr);

        int l = 0, r = 1e9; 
        int ans;

        while (l <= r) {
            int mid = (l + r) / 2;

            int cost = 0;
            
            vector<char> s2;

            for (int i = 0; i < n; i++) {
                if (arr[i] > mid) {
                    s2.push_back(s[i]);
                }
            }

            //print(s2);

            for (int i = 0; i < s2.size(); i++) {
                if (s2[i] == 'B') {
                    if (i - 1 < 0) {
                        cost++;
                    } else {
                        if (s2[i - 1] == 'R') {
                            cost++;
                        }
                    }
                }
            }


            //cout << "mid: " << mid << " cost: " << cost << endl;

            if (cost > k) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }

        }

        cout << ans << endl;
        //space;
    }


    return 0;
}
