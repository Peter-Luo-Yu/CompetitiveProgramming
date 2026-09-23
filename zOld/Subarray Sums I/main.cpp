#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, x; cin >> n >> x; 

    vector<int> arr (n); 
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    int ans = 0;
    int l = 0, r = 0, cur = 0;

    while (l < n && r < n){

        while (r < n){
            cur += arr[r++];

            if (cur > x){
                cur -= arr[--r];
                break;
            }
        }

        if (cur == x){
            ans++;
        }

        cur -= arr[l++];
    }

    cout << ans << endl;


    return 0;
}