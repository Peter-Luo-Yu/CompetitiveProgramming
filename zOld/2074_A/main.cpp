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
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            double root = sqrt(sum);
            int temp = root;

            //cout << "sqrt: " << root << " " << temp << endl;
            
            if ((root == temp) && (temp % 2 == 1)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
