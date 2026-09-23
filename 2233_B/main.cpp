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

        vector<int> two = {2, 1, 1, 2, 1, 2, 2, 1};
        vector<int> three = {1, 1, 2, 2, 3, 2, 3, 3, 2, 1, 3, 1};

        vector<int> ans (4 * n);
        if (n % 2 == 0) {
            int pos = ans.size() - 1;
            for (int i = 0; i < n - 2; i++) {
                ans[2*i] = i + 1; ans[2*i + 1] = i + 1;
                ans[pos] = i + 1; ans[pos - 2] = i + 1;
                if (i % 2 == 0) {
                    pos -= 1;
                } else {
                    pos -= 3;
                }
            }

            int idx = 0;
            for (int i = 2 * (n - 2); i < ans.size() - (2 * (n - 2)); i++) {
                if (two[idx] == 2) {
                    ans[i] = n;
                } else {
                    ans[i] = n - 1;
                }
                idx++;
            }

            print(ans);

        } else {
            int pos = ans.size() - 1;
            for (int i = 0; i < n - 3; i++) {
                ans[2*i] = i + 1; ans[2*i + 1] = i + 1;
                ans[pos] = i + 1; ans[pos - 2] = i + 1;
                if (i % 2 == 0) {
                    pos -= 1;
                } else {
                    pos -= 3;
                }
            }

            //print(ans);
            
            int idx = 0;
            for (int i = 2 * (n - 3); i < ans.size() - (2 * (n - 3)); i++) {
                if (three[idx] == 2) {
                    ans[i] = n;
                } else if (three[idx] == 1) {
                    ans[i] = n - 1;
                } else {
                    ans[i] = n - 2;
                }
                idx++;
            }

            print(ans);
            
        }

    }


    return 0;
}
