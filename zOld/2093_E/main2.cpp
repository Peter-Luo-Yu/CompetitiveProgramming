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

        vector<int> arr (n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        int l = 0, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            //cout << "mid: " << mid << endl;

            int cnt = 0;

            // once the current segment has all values
            // from 0 -> n - 1, the mex is automatically n
            vector<int> freq (mid);
            int missing = mid; 

            for (int i = 0; i < n; i++) {
                if (arr[i] < mid) {
                    if (freq[arr[i]] == 0) {
                        missing--;
                    }
                    freq[arr[i]]++;
                }

                if (missing == 0) {
                    cnt++;

                    freq = vector<int> (mid);
                    missing = mid;
                }
            }
            
            if (cnt >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }

          
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
