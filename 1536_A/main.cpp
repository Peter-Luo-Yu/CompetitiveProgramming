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
        map<int, int> freq;
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

       
        while (arr.size() <= 300) {
            bool add = false;

            for (int i = 0; i < arr.size() - 1; i++) {   
                for (int j = i + 1; j < arr.size(); j++) {
                    int diff = abs(arr[i] - arr[j]);
                    if (freq[diff] == 0) {
                        //cout << "diff: " << diff << endl;

                        arr.push_back(diff);
                        freq[diff]++;
                        add = true;
                        break;
                    }
                }
                if (add) {
                    break;
                }
            }

            if (!add) {
                break;
            }
        }

        if (arr.size() > 300) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << arr.size() << endl;
            print(arr);
        }

    }


    return 0;
}
