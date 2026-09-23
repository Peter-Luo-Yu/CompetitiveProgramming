#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--){
        ll n, k; cin >> n >> k;

        ll x1 = (-1*k + 0.5) + (sqrt((2*k-1)*(2*k-1)+4*(k*n+n*(n/2.0)-(n/2.0)))/2.0);
        ll x2 = x1+1;

        ll ans1 = -x1*x1 + (1-2*k)*x1 + k*n + n*n/2 - n/2;
        ll ans2 = -x2*x2 + (1-2*k)*x2 + k*n + n*n/2 - n/2;

        ans1 = abs(ans1); ans2 = abs(ans2);
        
        cout << min(ans1, ans2) << endl;
    }

    return 0;
}