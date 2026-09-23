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

    int n, m; cin >> n >> m;
    vector<int> a (n), b (m);

    ll sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; sumA += a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i]; sumB += b[i];
    }

    ll best = 1e12;
    int team, idx;

    for (int i = 0; i < n; i++) { // try removing from A
        ll tempA = sumA - a[i];

        if (abs(tempA - sumB) < best) {
            best = abs(tempA - sumB);
            team = 0; idx = i;
        }
    }
    for (int i = 0; i < n; i++) { // try removing from B
        ll tempB = sumB - b[i];

        if (abs(tempB - sumA) < best) {
            best = abs(tempB - sumA);
            team = 1; idx = i;
        }
    }

    cout << (team == 0 ? "A " : "B ") << idx + 1 << endl; 


    return 0;
}
