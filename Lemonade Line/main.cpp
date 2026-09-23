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

    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int n; cin >> n;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort (arr.begin(), arr.end());
    reverse (arr.begin(), arr.end());

    //print(arr);

    int cur = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= cur) {
            cur++;
        }
    }

    cout << cur << endl;


    return 0;
}
