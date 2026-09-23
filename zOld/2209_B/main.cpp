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

        vector<int> arr (n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            int cnt1 = 0, cnt2 = 0;

            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                   cnt1++;
                }
                if (arr[i] < arr[j]) {
                   cnt2++;
                }
            }

            cout << max(cnt1, cnt2) << " ";

        }

        cout << endl;
    }
    
    return 0;
}
