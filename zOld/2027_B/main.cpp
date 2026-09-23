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

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {cin>>arr[i];}

        int ans = 1e9;
        for (int i = 0; i < n; i++){ 
            int cost = i;
            for (int j = i + 1; j < n; j++){
                if (arr[j] > arr[i]){
                    cost++;
                }
            }
            ans = min (ans, cost);
        }

        cout << ans << endl;


    }
    
    return 0;
}