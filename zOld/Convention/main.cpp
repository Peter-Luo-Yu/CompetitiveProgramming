#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int n, m, c; cin >> n >> m >> c; // numcows, num busses, bus cap
    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());
    
    
    int l = 0, r = arr[arr.size() - 1];
    int ans = 0;
    while (l <= r) {
        int mid = (l+r)/2; // is the max wait time

        // simulate
        bool failed = false;
        
        int firstCow = -1; 
        int numCows = 0;
        int busses = m;

        for (int i = 0; i < arr.size(); i++) {
            if (firstCow == -1) {
                firstCow = arr[i];
                numCows++;

                //cout << "wait: " << mid << " t1: " << firstCow << " curCow: " << arr[i] << " #: " << numCows << " bus: " << busses << endl;
        
                continue;
            }

            if (arr[i] - firstCow <= mid && (numCows < c && busses > 0)) {
                numCows++;
            }
            else if ((arr[i] - firstCow > mid || numCows >= c) && busses > 1) { // don't fit
                busses--;
                numCows = 1;
                firstCow = arr[i];
            }
            else {
                failed = true;
            }

            //cout << "wait: " << mid << " t1: " << firstCow << " curCow: " << arr[i] << " #: " << numCows << " bus: " << busses << endl;
        }

        //cout << "failed: " << failed << endl;

        if (failed) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }

    }

    cout << ans << endl;
    

    return 0;
}