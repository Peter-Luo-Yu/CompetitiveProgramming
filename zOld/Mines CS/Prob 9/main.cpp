#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    while (n--){
        int l = 0, r = 0;

        int k, d; cin >> k >> d;

        for (int i = 0; i < k; i++){
            if (i % 2 == 0){
                l+=2;
            } else {
                r+=2;
            }
        }

        int check = d % gcd(l,r);

        if (check != 0){
            cout << "impossible" << endl;
            continue;
        }

        
        
    }

    return 0;
}