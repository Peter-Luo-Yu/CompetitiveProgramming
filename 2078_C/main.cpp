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

        vector<ll> arr (2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> arr[i];
        sort (arr.begin(), arr.end());

        //print(arr);

        ll Max = arr[2*n - 1];

        ll sum1 = 0;
        for (int i = 2 * n - 2; i >= n - 1; i--) {
            sum1 += arr[i];
        } 
        ll sum2 = 0;
        for (int i = n - 2; i >= 0; i--) {
            sum2 += arr[i];
        }
        
        //cout << sum1 << " " << sum2 << endl;

        ll missing = Max + sum1 - sum2;

        cout << Max << " " << missing << " ";
        for (int i = 0; i < n - 1; i++) {
            cout << arr[n + i - 1] << " " << arr[i] << " ";
        }
        cout << arr[2 * n - 2] << endl;

        //space;
    }   
    


    return 0;
}
