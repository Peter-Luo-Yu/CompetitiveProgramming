#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());

    int l = 1, r = arr[arr.size() - 1];
    int ans;
    while (l <= r) {
        int mid = (l+r)/2;

        int cost = 1;

        int start = -1;
        for (int i = 0; i < n; i++) {
            if (start == -1) {
                start = arr[i]; continue;
            }

            if (arr[i] - start <= 2 * mid) {

            } else {
                cost++;
                start = arr[i];
            }
            
            //cout << "mid: " << mid << " start: " << start << " cost: " << cost << endl;
        }
        
        

        if (cost > k) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }

    cout << ans << endl;
    

    return 0;
}