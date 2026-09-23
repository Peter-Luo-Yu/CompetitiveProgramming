#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n,k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());

    //print(arr);

    vector<int> sizes (n);
    int l = 0, r = 0;
    while (l < n){
        while (r < n && arr[r] - arr[l] <= k){
            r++;
        }
        sizes[l] = r - l;
        l++;
    }
    //print(sizes);

    vector<int> max_val_after_i (n+1);
    max_val_after_i[n] = 0;
    for (int i = n - 1; i >= 0; i--){
        max_val_after_i[i] = max(max_val_after_i[i + 1], sizes[i]);
    }

    //print(max_val_after_i);

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max (ans, sizes[i] + max_val_after_i[i + sizes[i]]);
    }
    cout << ans << endl;

    return 0;
}