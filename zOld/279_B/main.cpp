#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, t; cin >> n >> t;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    
    int ans = 0; 

    int cur = 0, l = 0, r = 0;

    while (l < n && r < n){
        while (r < n){
            cur += arr[r];
            r++;

            if (cur > t){
                r--;
                cur -= arr[r];
                break;
            }
        }

        ans = max (ans, r-l);
        cur -= arr[l]; 
        l++;
    }

    cout << ans << endl;

    return 0;
}