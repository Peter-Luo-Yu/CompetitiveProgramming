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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> arr (n);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        arr[i] = {val, i};
    }

    sort (arr.begin(), arr.end());
    
    printP(arr);

    // move max to the bottom, everybody offset by 1
    int cost = 0;
    vector<bool> vis (n);
    
    for (int i = n - 1; i > 0; i--) {   
        cout << "pos: " << arr[i].second << " goal: " << i;
        cout << " cost: " << i - arr[i].second << endl;

        vis[arr[i].second] = true;
        cost += i - arr[i].second;



    }
    
    cout << cost << endl;

    
    return 0;
}
