#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> arr (n);
        vector<int> is_locked (2 * n);
        vector<int> count (2 * n);
        for (int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            arr[i] = {a, b};
            if (a == b){
                is_locked[a - 1] = 1;
                count[a - 1]++;
            }
        }

        vector<int> prefix (2 * n + 1);
        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + is_locked[i];
        }

        //cout << "islock: "; print(is_locked);
        //cout << "count: "; print(count);
        //cout << "prefix: "; print(prefix);

        vector<int> ans (n);
        for (int i = 0; i < n; i++) {
            if (arr[i].first == arr[i].second) {
                if (count[arr[i].first - 1] > 1) {
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                }
            } else {
                int locked_count = prefix[arr[i].second] - prefix[arr[i].first - 1];
                //cout << "i: " << i << " locked: " << locked_count << endl;

                if (locked_count < (arr[i].second - arr[i].first + 1)) {
                    ans[i] = 1;
                } else {
                    ans[i] = 0;
                }
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
        
    }    
    return 0;
}
