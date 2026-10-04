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
        string s; cin >> s;

        int ans = 0;
        vector<int> arr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '4') { 
                arr.push_back(s[i] - '0');
            }
            else {
                ans++;
            }
        }

        vector<int> prefodd(arr.size() + 1), sufeven(arr.size() + 1);

        for (int i = 0; i < arr.size(); i++) {
            prefodd[i + 1] = prefodd[i] + (arr[i] == 1 || arr[i] == 3);
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            sufeven[i] = sufeven[i + 1] + (arr[i] == 2);
        }

        //print(arr); print(prefodd); print(sufeven);
        
        int best = 1e9;
        for (int i = 0; i < prefodd.size(); i++) {
            best = min (best, (prefodd[i] + sufeven[i]));
        }

        ans += best;

        cout << ans << endl;


        //space;
    }


    return 0;
}
