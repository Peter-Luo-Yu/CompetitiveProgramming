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
        int n; cin >> n;
        
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        for (int i = 1; i < n/2; i++){
            if (arr[i] == arr[i-1] || arr[n - i - 1] == arr[n - i]){
                swap(arr[i], arr[n - i - 1]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n - 1; i++){
            ans += (arr[i] == arr[i + 1]);
        }

        cout << ans << endl;
    }
    
    return 0;
}