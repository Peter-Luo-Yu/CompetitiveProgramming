#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> arr;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        vector<int> temp (n);
        for (int j = 0; j < n; j++) {
            temp[j] = s[j] - '0';
        }

        arr.push_back(temp);
    }

    //print2d(arr);

    bool horizontal = false, vertical = false;
    int total = 0, countH = 0, countV = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                total++;
            } 
        }
    }

    //cout << "total: " << total << endl;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                count++;
            } 
        }

        countH = max (countH, count);
    }

    //cout << countH << endl;
    
    // total flips = (total - countH) + (n - countH)
    if (total - countH + n - countH <= n) {
        horizontal = true;
    }

    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == 1) {
                count++;
            } 
        }

        countV = max (countV, count);
    }

    //cout << countV << endl;
    
    // total flips = (total - countH) + (n - countH)
    if (total - countV + n - countV <= n) {
        vertical = true;
    }

    if (vertical && horizontal) {
        cout << "+" << endl;
    } 
    else if (vertical) {
        cout << "|" << endl;
    } else {
        cout << "-" << endl;
    }
    

    return 0;
}