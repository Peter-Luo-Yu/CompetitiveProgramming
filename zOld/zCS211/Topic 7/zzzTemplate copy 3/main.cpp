#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, m, c; cin >> n >> m >> c;
    vector<ll> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    map<ll, ll> freq;

    for (int i = 0; i < m; i++) {
        freq[arr[i]]++;
    }
    //printP(freq);

    vector<ll> diff;
    diff.push_back(freq.rbegin() -> first - freq.begin() -> first);

    for (int i = m; i < n; i++) {
        freq[arr[i]]++;
        freq[arr[i - m]]--;
        if (freq[arr[i - m]] == 0) {
            freq.erase(arr[i - m]);
        }

        //printP(freq);

        diff.push_back(freq.rbegin() -> first - freq.begin() -> first);
    }

    //print(diff);

    bool found = false;
    for (int i = 0; i < diff.size(); i++) {
        if (diff[i] <= c) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "NONE" << endl;
    } else {
        for (int i = 0; i < diff.size(); i++) {
            if (diff[i] <= c) {
                cout << i + 1 << endl;
            }
        }
    }

    return 0;
}
