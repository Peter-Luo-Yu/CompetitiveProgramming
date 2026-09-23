#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, m, h; cin >> n >> m >> h;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        vector<pair<int, int>> data;
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--;
            data.push_back({a,b});
        }

        vector<int> ans = arr;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            ans[data[i].first] += data[i].second;

            //cout << "hi: ";
            //print(ans);
            
            if (ans[data[i].first] > h) {
                for (int j = idx; j <= i; j++) {
                    ans[data[j].first] -= data[j].second;
                }
                idx = i + 1;
            }
        }

        print(ans);

    }
    

    return 0;
}