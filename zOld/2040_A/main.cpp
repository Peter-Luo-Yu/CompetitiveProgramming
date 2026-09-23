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

    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;

        vector<int> arr (n); 
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        int ans = -1;

        for (int i = 0; i < n; i++){
            bool failed = false;

            for (int j = 0; j < n; j++){
                if (i == j) {continue;}

                if (abs(arr[i] - arr[j]) % k == 0){
                    failed = true;
                    break;
                }
            }

            if (!failed){
                ans = i + 1;
            }
        }

        if (ans == -1){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << ans << endl;
        }

    }
    

    return 0;
}