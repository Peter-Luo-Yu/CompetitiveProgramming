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

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr (n);
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        // val - freq
        vector<pair<int, int>> a; 
        for (auto x : freq) {
            a.push_back({x.first, x.second});
        }
        reverse(a.begin(), a.end());
    
        //printP(a);

        bool success = false;

        int m = a[0].first;
        if (a[0].second % 2 == 0) {
            success = true;
        }
        for (int i = 1; i < a.size(); i++) {
            if (a[i].first < m - k) {
                m = a[i].first;
                if (a[i].second % 2 == 0) {
                    //cout << "c1" << endl;
                    success = true;
                } 
            }
            else {
                //cout << "c2" << endl;
                success = true;
            }
        }

        cout << (success ? "YES" : "NO") << endl;


        //space;
    }
    


    return 0;
}
