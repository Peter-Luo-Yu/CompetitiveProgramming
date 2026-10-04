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
    vector<int> h (n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    vector<int> arr;
 
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(arr.begin(), arr.end(), h[i]) - arr.begin();
 
        if (pos == arr.size()) {
            arr.push_back(h[i]);
        }
        else {
            arr[pos] = h[i];
        }
 
        //print(arr);
    }
 
    cout << arr.size() << endl;
 
 
    return 0;
}