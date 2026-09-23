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

    int n, l; cin >> n >> l;

    vector<int> d(n), w(n);

    for (int i = 0; i < n; i++) {cin >> d[i];}
    for (int i = 0; i < n; i++) {cin >> w[i];}

    int v; cin >> v;

    d.push_back(l);


    ld curPos = d[0], curT = d[0];

    ld debt = 0;

    for (int i = 1; i <= n; i++) {
        int totalT = d[i] - d[i - 1];

        ld travelT = (ld) (d[i] - d[i - 1]) / v;

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

    if (curPos == l) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


   
    
    return 0;
}
