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
        vector<int> arr (n), one(n + 1), two(n + 1), three(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            one[i + 1] = one[i] + (arr[i] == 1);
            two[i + 1] = two[i] + (arr[i] == 2);
            three[i + 1] = three[i] + (arr[i] == 3);
        }

        vector<int> sufMax (n + 1, -1e9);
        for (int i = n - 1; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], one[i] + two[i] - three[i]);
        }

        //cout << "  "; print(arr); print(one); print(two); print(three); print(sufMax);

        // first: want ones >= twos and threes
        // second: want ones + twos >= threes
        bool good = false;
        for (int i = 1; i < n - 1; i++) {
            if (one[i] >= two[i] + three[i]) {
                
                //cout << "i: " << i << " | one: " << one[i] << " two: " << two[i] << " three: " << three[i] << endl;
                
                int val = one[i] + two[i] - three[i];

                //cout << "val: " << val << endl;

                if (val <= sufMax[i + 1]) {
                    good = true;
                }
            }
        }

        cout << (good ? "YES" : "NO") << endl;
        
        //space;
    }


    return 0;
}
