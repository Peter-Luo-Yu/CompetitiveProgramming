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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        bool allsame = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                allsame = false;
            }
        }
        if (allsame) {
            for (int i = 0; i < n; i++) {
                cout << arr[i];
            } cout << endl;
            continue;
        }

        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        int Max = 0;
        char maxchar; 
        int Min = 1e9;
        char minchar;
        for (auto x : mp) {
            if (x.second > Max) {
                Max = x.second;
                maxchar = x.first;
            }
        }

        for (auto x : mp) {
            if (x.first == maxchar) {
                continue;
            }
            if (x.second < Min) {
                Min = x.second;
                minchar = x.first;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == minchar) {
                arr[i] = maxchar;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i];
        } cout << endl;

        //cout << maxchar << " " << Max  << " " << minchar << " " << Min << endl;
    }

    
    return 0;
}
