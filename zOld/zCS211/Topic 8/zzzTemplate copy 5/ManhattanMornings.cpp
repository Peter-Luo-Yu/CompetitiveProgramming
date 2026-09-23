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

// Link: https://github.com/benjaminzwhite/kattis/blob/main/src/manhattanmornings.py#L11
// This: https://gemini.google.com/share/95732efd69cd
// This was a fun problem, but once again I had trouble with implementation, and 
// I didn't even realize that it was LIS, I was just trying think about which paths to take 
// after we sorted by x coordinate.

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    bool revX = false, revY = false;

    if (x1 > x2) {
        revX = true;
        x1 = -x1;
        x2 = -x2;
    }
    if (y1 > y2) {
        revY = true;
        y1 = -y1;
        y2 = -y2;
    }

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        if (revX) {
            x = -x;
        }
        if (revY) {
            y = -y;
        }

        if ((x1 <= x) && (x <= x2) && (y1 <= y) && (y <= y2)) {
            arr.push_back({x, y});
        }
    }

    sort (arr.begin(), arr.end());
    

    // Do the LIS on arr[i].second
    // dp [i] is LIS ending at i.
    vector<int> notdp;

    for (int i = 0; i < arr.size(); i++) {  
        int y = arr[i].second;  // each element by itself is an LIS of len 1

        int idx = upper_bound(notdp.begin(), notdp.end(), y) - notdp.begin();
        
        if (idx >= notdp.size()) {
            notdp.push_back(y);

        } else {
            notdp[idx] = y;
        }
        
    }


    cout << notdp.size() << endl;
    
    return 0;
}
