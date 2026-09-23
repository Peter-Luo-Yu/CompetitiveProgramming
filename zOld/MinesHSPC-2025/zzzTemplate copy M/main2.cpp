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

    int n, end; cin >> n >> end;

    vector<int> d(n), w(n);

    for (int i = 0; i < n; i++) {cin >> d[i];}
    for (int i = 0; i < n; i++) {cin >> w[i];}

    d.push_back(end);


    ld ans = -1;
    ld l = 0, r = 3 * 1e8;

    while (r - l >= 1e-8) {
        ld mid = (l + r) / (ld) 2;   // guess on V

        //cout << "MID: " << mid << endl;

        ld curPos = d[0], curT = d[0];

        ld debt = 0;

        for (int i = 1; i <= n; i++) {

            int totalT = d[i] - d[i - 1];

            ld travelT = (ld) (d[i] - d[i - 1]) / mid;

            ld needT = travelT + w[i - 1] + debt;

            debt = max((ld) 0, needT - totalT);

            //cout << "totalT: " << totalT << " travel: " << travelT << " need: " << needT << " debt: " << debt << endl;
        
            if (debt == 0) {
                curPos = d[i];
                curT = d[i];
            } else {
                curT = d[i];
            }

            //cout << "curPos: " << curPos << " curT: " << curT << endl;
        }

        if (curPos == end) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }
    

    if (ans == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << fixed << setprecision(6) << ans << endl;
    }
   
    
    return 0;
}
