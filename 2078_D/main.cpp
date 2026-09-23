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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<pair<char, ll>> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i].first >> l[i].second;
            cin >> r[i].first >> r[i].second;
        }

        vector<ll> suffL(n + 1, 1), suffR(n + 1, 1);
        // place a person before suff[i], how many times will he be multiplied by the end

        for (int i = n - 1; i >= 0; i--) {
            if (l[i].first == 'x') {
                suffL[i] = suffL[i + 1] * l[i].second;
            } else {
                suffL[i] = suffL[i + 1];
            }

            if (r[i].first == 'x') {
                suffR[i] = suffR[i + 1] * r[i].second;
            } else {
                suffR[i] = suffR[i + 1];
            }
        }

        //print(suffL);
        //print(suffR);

        ll left = 1, right = 1;

        for (int i = 0; i < n; i++) {
            ll gl = 0, gr = 0;

            if (l[i].first == 'x') {
                gl = left * (l[i].second - 1);
            } else {
                gl = l[i].second;
            }

            if (r[i].first == 'x') {
                gr = right * (r[i].second - 1);
            } else {
                gr = r[i].second;
            }

            ll gain = gl + gr;

            if (suffL[i + 1] >= suffR[i + 1]) {
                left += gain;
            } else {
                right += gain;
            }
        } 

        cout << left + right << endl;

        space;
    }


    return 0;
}
