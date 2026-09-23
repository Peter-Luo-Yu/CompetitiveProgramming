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

        vector<char> arr (n - 1);
        string s; cin >> s;
        for (int i = 0; i < n - 1; i++) {
            arr[i] = s[i];
        }

        int l = 1, r = n;
        vector<int> ans (n - 1);
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] == '<') {
                ans[i] = l;
                l++;
            } else {
                ans[i] = r;
                r--;
            }
        }

        cout << l << " ";

        print(ans);
    }


    return 0;
}
