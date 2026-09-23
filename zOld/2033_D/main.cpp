#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        int l = 0, r = 0;
        int cur = 0, ans = 0;

        while (l < n){
            cur += arr[l];

            if (cur == 0){
                ans++;
                l = r + 1, r = l;
            }
            else {
                while (cur != 0 && r + 1 < n){
                r++;
                cur += arr[r];
                }
                if (cur == 0){
                    ans++;
                    l = r + 1, r = l;
                }

                l++; r = l; cur = 0;
            }
            
        }

        cout << ans << endl;

    }
    

    return 0;
}