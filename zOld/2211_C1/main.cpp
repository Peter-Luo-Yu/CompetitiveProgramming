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

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < n; i++) {cin >> b[i];}


        int check = n - k;

        //cout << "check: " << check << endl;

        if (check >= n / 2) {   // a must equal b;
            bool failed = false;

            for (int i = 0; i < n; i++) {
                if (b[i] != -1 && a[i] != b[i]) {
                    failed = true;
                }
            }

            if (failed) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }

        } else {
            bool failed = false;

            for (int i = 0; i < check; i++) {
                //cout << i << endl;
                if (b[i] != -1 && a[i] != b[i]) {
                    failed = true;
                }
            }
            for (int i = n - 1; i > n - 1 - check; i--) {
                //cout << i << endl;
                if (b[i] != -1 && a[i] != b[i]) {
                    failed = true;
                }
            }

            if (failed) {
                cout << "NO" << endl;
                continue;
            }

            map<int, int> freq;
            for (int i = check; i < n - check; i++) {
                //cout << "adding: " << a[i] << endl;
                freq[a[i]]++;
            }

            for (int i = check; i < n - check; i++) {
                if (b[i] == -1) {
                    freq[b[i]]++;
                }
                else {
                    if (freq.count(b[i]) > 0) {
                        freq[b[i]]--;
                    } else {

                    }
                }
            }

            int cnt = 0;

            for (auto x : freq) {
                if (x.first != -1 && x.second > 0) {
                    cnt++;
                }
            }

            //cout << "cnt: " << cnt << " || -1: " << freq[-1] << endl;

            if (cnt != freq[-1]) {
                failed = true;
            }

            if (failed) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }

        }



    }
    
    return 0;
}
