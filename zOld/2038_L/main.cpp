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

    int n; cin >> n;

    if (n == 1){
        cout << 2 << endl;
    }
    else if (n == 2){
        cout << 3 << endl;
    }
    else if (n == 3){
        cout << 4 << endl;
    }
    else {
        if (n % 3 == 0){ //  21-21-18 and 18-18-21 and 25-25 
            cout << (n/3) + (n/3) + ((n/2) + ((n % 2) != 0)) << endl;
        }
        else if (n % 3 == 1){  // now we have a 21 and a 18 leftover, could have 25 left over too
            int ans = (n/3) + (n/3) + (n/2);
            if (n % 2 == 0){
                ans += 1;
            } else {
                ans += 2;
            }
            cout << ans << endl;
        }
        else {  
            int ans = (n/3) + (n/3) + (n/2);

            if (n % 2 == 0){
                ans += 2;
            } else {
                ans += 2;
            }
            cout << ans << endl;

        }
    }
   

    return 0;
}