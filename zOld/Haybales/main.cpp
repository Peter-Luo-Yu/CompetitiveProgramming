#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());

    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        cout << (upper_bound(arr.begin(), arr.end(), r) - arr.begin()) - 
                (lower_bound(arr.begin(), arr.end(), l) - arr.begin()) << endl;
    }

    return 0;
}