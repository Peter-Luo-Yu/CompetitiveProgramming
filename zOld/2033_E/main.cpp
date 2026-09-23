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

        vector<bool> vis (n);
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (vis[i] == true) {continue;}
            int len = 0;

            int j = i;
            while (vis[j] == false){
                vis[j] = true;
                len++;
                j = arr[j] - 1;  // remember it is 0 - indexed
            }
            ans += (len-1)/2;
        }
        cout << ans << endl;

    }
    

    return 0;
}