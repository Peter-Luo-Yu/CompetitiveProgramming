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

    int n; cin >> n;
    vector<int> x(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> a[i] >> b[i];
    }

    vector<pair<ld, int>> slopes;

    for (int i = 0; i < n; i++) {
        slopes.push_back({(ld) a[i]/ (ld) x[i], 0});
        slopes.push_back({(ld) b[i]/ (ld) x[i], 1});
    }
   
    sort (slopes.begin(), slopes.end());

    //printP(slopes);

    // running sum - difference array problem

    vector<int> diff (slopes.size());

    for (int i = 0; i < slopes.size(); i++) {
        if (slopes[i].second == 0) {
            diff[i] = 1;
        } else {
            diff[i] = -1;
        }
    }


    //print(diff);

    vector<int> prefix (diff.size() + 1);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + diff[i];
    }

    //print(prefix);

    cout << *max_element(prefix.begin(), prefix.end()) << endl;


    return 0;
}
