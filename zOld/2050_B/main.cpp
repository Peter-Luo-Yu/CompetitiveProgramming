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

        ll sum = 0;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }
        
        ll avg = sum / n;

        ll sum1 = 0, sum2 = 0;
        int ele1 = 0, ele2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sum1 += arr[i];
                ele1++;
            } else {
                sum2 += arr[i];
                ele2++;
            }
        }

        if (sum1 % avg == 0 && sum2 % avg == 0 && sum1 >= ele1 * avg && sum2 >= ele2 * avg) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
