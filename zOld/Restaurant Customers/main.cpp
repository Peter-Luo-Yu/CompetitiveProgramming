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

    int n; cin >> n;

    vector<pair<int, int>> data;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        
        data.push_back({a, 0}); // 0 = start
        data.push_back({b, 1}); // 1 = end;
    }

    sort (data.begin(), data.end());

    vector<int> diff (data.size());
    for (int i = 0; i < data.size(); i++) {
        if (data[i].second == 0) {
            diff[i] = 1;
        } else {
            diff[i] = -1;
        }
    }

    //print(diff);

    vector<int> pref (diff.size() + 1);
    
    for (int i = 1; i <= diff.size(); i++) {
        pref[i] = pref[i - 1] + diff[i - 1];
    }

    //print(pref);

    cout << *max_element(pref.begin(), pref.end()) << endl;
    
    
    return 0;
}
