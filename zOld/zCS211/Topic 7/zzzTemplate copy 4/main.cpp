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

    int n, h; cin >> n >> h;

    vector<pair<int, int>> arr;

    bool bottom = true;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (bottom) {
            arr.push_back({0, 1});
            arr.push_back({val, 2});
        } else {
            arr.push_back({h, 2});
            arr.push_back({h - val, 1});
        }
        bottom = !bottom;
    }

    sort (arr.begin(), arr.end());
    
    //printP(arr);

    int count = 0;
    int minCount = 1e9;
    int height = 0; 
    int idx = 0;

    for (int i = 0; i < h; i++) {
        //cout << "cur h: " << i << endl;
        while (arr[idx].first == i) {
            
            if (arr[idx].second == 1) {
                count++;
            } else {
                count--;
            }
            idx++;
        }

        minCount = min(minCount, count);

        //cout << "count: " << count << endl;
    }

    //cout << "min: " << minCount << endl;

    int numlevels = 0;
    count = 0;
    idx = 0;
    for (int i = 0; i < h; i++) {
        //cout << "cur h: " << i << endl;
        while (arr[idx].first == i) {
            
            if (arr[idx].second == 1) {
                count++;
            } else {
                count--;
            }
            idx++;
        }

        if (count == minCount) {
            numlevels++;
        }
    }


    cout << minCount << " " << numlevels << endl;


    return 0;
}
