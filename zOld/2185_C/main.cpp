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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        sort (arr.begin(), arr.end());
        
        //cout << "arr: "; print(arr);


        int Max = -1;
        int count = 1, prev = arr[0];

        for (int i = 1; i < n; i++) {
            //cout << "count: " << count << " prev: " << prev << endl;
            if (arr[i] == prev) {

            }
            else if (arr[i] == prev + 1) {
                count++; prev = arr[i];
            }
            else {
                Max = max (count, Max);
                count = 1; prev = arr[i];
            }
        }
        Max = max (count, Max);

        cout << Max << endl;
        


    }
    

    return 0;
}