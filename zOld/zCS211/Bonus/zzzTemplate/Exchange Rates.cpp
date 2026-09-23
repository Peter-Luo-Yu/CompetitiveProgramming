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

    int n;
    do {
        cin >> n;
        if (n == 0) break;

        //cout << "N: " << n << endl;

        vector<ld> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        //print(arr);


        // dp[i] max CAN dollars at time i
        vector<ld> dp1 (n), dp2 (n);
        dp1[0] = 1000; 

        for (int i = 0; i < n; i++) {

            ld mostCAN = -1;
            for (int j = 0; j <= i; j++) {
                mostCAN = max (mostCAN, dp1[j]);
            }
            //cout << mostCAN << endl;

            ld convert1 = mostCAN * (ld) 0.97 / arr[i];
            int temp = convert1 * 100;
            convert1 = (ld) temp / (ld) 100;


            dp2[i] = max (dp2[i], convert1);
            


            ld mostUSD = -1;
            for (int j = 0; j < i; j++) {
                mostUSD = max (mostUSD, dp2[j]);
            }

            ld convert2 = mostUSD * (ld) 0.97 * arr[i];
            temp = convert2 * 100;
            convert2 = (ld) temp / (ld) 100;

            dp1[i] = max (dp1[i], convert2);
        }

        //print(dp1);
        //print(dp2);


        ld ans = -1;

        for (int i = 0; i < dp1.size(); i++) {
            ans = max (ans, dp1[i]);
        }

        cout << fixed << setprecision(2) << ans << endl;

        //space;

    } while (n != 0);

    return 0;
}
