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
        int n; cin >> n;

        vector<int> arr (n);

        int numEven = 0, numOdd = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            if (arr[i] % 2 == 0) {
                numEven++;
            } else {
                numOdd++;
            }
        }

        //cout << numEven << " " << numOdd << endl;

        int ans1 = 0, ans2 = 0;

        if (numEven > 0) {
            ans1 = 1 + numOdd;
        }
        if (numEven <= 0) {
            ans2 = numOdd - 1;
        }

        cout << max (ans1, ans2) << endl;
    }
    
    
    return 0;
}
