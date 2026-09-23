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

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        vector<int> query(m), arr (k);
        for (int i = 0; i < m; i++) {cin >> query[i];}
        for (int i = 0; i < k; i++) {cin >> arr[i];}

        int idx = 0;
        map<int, int> dontknow;
        for (int i = 1; i <= n; i++) {
            if (arr[idx] < i) {
                idx++;
            }
            if (idx > arr.size() - 1) {
                dontknow[i] = 1;
            }
            else if (arr[idx] != i) {
                dontknow[i] = 1;
            }
        }

        //print(arr); print(query);
        //for (auto x : dontknow) {
        //    cout << x.first << " " << x.second << endl;
        //}

        vector<int> ans;
        if (dontknow.size() < 1) {
            for (int i = 0; i < query.size(); i++) {
                ans.push_back(1);
            }
        } 
        else if (dontknow.size() > 1) {
            for (int i = 0; i < query.size(); i++) {
                ans.push_back(0);
            }
        }
        else {

            for (int i = 0; i < query.size(); i++) {
                if (dontknow.count(query[i]) > 0) {
                    ans.push_back(1);
                } else {
                    ans.push_back(0);
                }
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        } cout << endl;

    }
    
    return 0;
}
