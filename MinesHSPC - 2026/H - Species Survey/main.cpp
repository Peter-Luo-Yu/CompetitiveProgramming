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

    int n, q; cin >> n >> q;

    // species - family
    map<string, string> mp;
    for (int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        mp[s1] = s2;
    }

    // cnt for each species, cnt for each family;
    map<string, int> Scnt, Fcnt;

    for (int i = 0; i < q; i++) {
        int t; cin >> t;

        if (t == 1) {
            string s; int c;
            cin >> s >> c;

            Scnt[s] += c;
            Fcnt[mp[s]] += c;
        }
        else if (t == 2) {
            string s; cin >> s;
            cout << Scnt[s] << endl;
        }
        else {
            string f; cin >> f;
            cout << Fcnt[f] << endl;
        }

    }

    


    return 0;
}
