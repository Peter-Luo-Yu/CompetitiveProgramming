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

vector<vector<int>> adj;

bool cmp (int a, int b) {
    if (adj[a][b] == 1) {   // connection means a < b
        return a < b;
    } else {
        return a > b;
    }
    
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        adj = vector<vector<int>> (n, vector<int> (n));

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(i);

            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') {
                    adj[i][j] = 1;
                } else {
                    adj[i][j] = 0;
                }
            }
        }

        //printG(adj);

        //print(ans);

        sort (ans.begin(), ans.end(), cmp);

        //print(ans);

        for (auto a : ans) {
            cout << a + 1 << " ";
        }
        cout << endl;

    }


    
    return 0;
}
