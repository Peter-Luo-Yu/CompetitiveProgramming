#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n; cin >> n;
    
    vector<int> herd (n);
    for (int i = 0; i < n; i++) {cin >> herd[i];}
    sort (herd.begin(), herd.end());

    int min_moves = INT32_MAX;
    if (herd[n-2] - herd[0] == n - 2 && herd[n-1] - herd[n-2] > 2){
        min_moves = 2;
    }
    else if (herd[n-1] - herd[1] == n - 2 && herd[1] - herd[0] > 2){
        min_moves = 2;
    }
    else {
        int r = 0;
        for (int l = 0; l < n; ++l){
            while (r+1 < n && herd[r+1] - herd[l] < n){
                r++;
            }
            min_moves = min (min_moves, n - (r - l + 1));
        }
    }

    int gap_num = 0;
    for (int i = 1; i < n; i++) {
        gap_num += herd[i] - herd[i-1] - 1;
    }

    int max_moves = max (gap_num - (herd[1] - herd[0] - 1), gap_num - (herd[n-1] - herd[n-2] - 1));

    cout << min_moves << endl << max_moves << endl;
    return 0;
}