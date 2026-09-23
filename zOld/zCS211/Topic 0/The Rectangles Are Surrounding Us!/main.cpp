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

    int t = -1;

    while (t != 0) {
        cin >> t;
        if (t == 0) break;

        vector<vector<int>> arr (t);
        for (int i = 0; i < t; i++) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            c--; d--;
            arr[i] = {a,b,c,d};
        }

        ll ans = 0;
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 500; j++) {
                for (int k = 0; k < arr.size(); k++) {
                    if ((i >= arr[k][0] && i <= arr[k][2]) && (j >= arr[k][1] && j <= arr[k][3])) {
                        //cout << i << " " << j << endl;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    

    return 0;
}