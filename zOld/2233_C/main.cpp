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
        vector<char> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> ans (n);

        while (k > 0) {

            vector<int> pref(n + 1), suf(n + 1);

            for (int i = 0; i < n; i++) {
                if (arr[i] == '(') {
                    pref[i + 1] = pref[i] + 1;
                } else {
                    pref[i + 1] = pref[i];
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] == ')') {
                    suf[i] = suf[i + 1] + 1;
                } else {
                    suf[i] = suf[i + 1];
                }
            }

            vector<int> score (n);

            for (int i = 0; i < n; i++) {
                if (arr[i] == '(') {
                    score[i] = suf[i + 1];
                } else {
                    score[i] = pref[i];
                }
            }

            
            int Max = -1, idx = -1;

            for (int i = 0; i < score.size(); i++) {
                if (ans[i] == 1) continue;

                if (score[i] > Max) {
                    Max = score[i];
                    idx = i;
                }
            }

            arr[idx] = '-';
            ans[idx] = 1;
            k--;

            //print(arr); print(pref); print(suf); print(score);

            //space;
        }

        for (auto i : ans) {
            cout << i;
        }
        cout << endl;

        //space; space;
    }


    return 0;
}
