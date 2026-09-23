#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> arr (n); for (int i = 0; i < n; i++) {cin >> arr[i];}

    for (int i = 0; i < k; i++){
        int q; cin >> q;
        
        cout << upper_bound (arr.begin(), arr.end(), q) - arr.begin() << endl;
       
    }

    return 0;
}