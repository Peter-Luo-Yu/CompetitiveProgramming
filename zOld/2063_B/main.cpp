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
        int n, l, r; cin >> n >> l >> r; l--, r--;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];


        vector<int> left, mid, right;
        ll sum = 0;

        for (int i = 0; i < l; i++) {
            left.push_back(arr[i]);
        }
        for (int i = r + 1; i < n; i++) {
            right.push_back(arr[i]);
        }
        for (int i = l; i <= r; i++) {
            sum += arr[i];
            mid.push_back(arr[i]);
        }

        sort (left.begin(), left.end());
        sort (mid.begin(), mid.end());
        sort (right.begin(), right.end());

        //print(left); print(mid); print(right);

        ll diff1 = 0, diff2 = 0;

        int midIdx = mid.size() - 1;
        for (int i = 0; i < min(mid.size(), left.size()); i++) {
            if (left[i] - mid[midIdx] < 0) {
                diff1 += left[i] - mid[midIdx];
                midIdx--;
            }
        }

        midIdx = mid.size() - 1;
        for (int i = 0; i < min(mid.size(), right.size()); i++) {
            if (right[i] - mid[midIdx] < 0) {
                diff2 += right[i] - mid[midIdx];
                midIdx--;
            }
        }

        //cout << "one: " << diff1 << " two: " << diff2 << endl;

        ll ans = sum + min(diff1, diff2);

        cout << ans << endl;

        

    }
    
    
    return 0;
}
