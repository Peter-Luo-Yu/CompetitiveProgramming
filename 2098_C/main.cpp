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
        int n; cin >> n;
        vector<int> arr (n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        sort (arr.begin(), arr.end());

        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        bool four = false;
        for (auto x : freq) {
            if (x.second >= 4) {
                four = true;
            }
        }

        int two_cnt = 0;
        int prev = -1;
        bool good = false;
        for (auto x : freq) {
            if (x.first != prev + 1) {
                if (two_cnt >= 2) {
                    good = true;
                }
                two_cnt = 0;
                prev = x.first;
                if (x.second >= 2) {
                    two_cnt++;
                }
            }
            else {
                if (x.second >= 2) {
                    two_cnt++;
                }
                prev = x.first;
            }

            //cout << "prev: " << prev << " cnt: " << two_cnt << endl;
        }

        if (two_cnt >= 2) {
            good = true;
        }


        if (four || good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }


    return 0;
}
