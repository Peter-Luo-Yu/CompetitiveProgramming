#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int l, r; cin >> l >> r;

        if (l % 2 == 0){
            l++;
        } 
        if (r % 2 == 0){
            r--;
        }

        int numodds = ((r-l)/2) + 1;
        cout << numodds/2 << endl;
    }
    
    return 0;
}