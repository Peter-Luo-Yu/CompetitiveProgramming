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

        string s; cin >> s;

        map<pair<int, int>, int> freq;

        int d = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                d++; 
            } else {
                k++;
            }

            int rd = d / gcd(d, k);
            int rk = k / gcd(d, k);

            freq[{rd, rk}]++;

            cout << freq[{rd, rk}] << " ";
        }
        cout << endl;

    }


    return 0;
}
