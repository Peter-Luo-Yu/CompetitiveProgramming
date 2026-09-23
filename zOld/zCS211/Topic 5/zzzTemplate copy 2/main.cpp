#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ld d, s; cin >> d >> s;

    // BS on a, duh?
    ld l = 0, r = 2e18;
    ld e = 2.71828182845904523536028747135266250;
    ld a;
    while (r - l >= 1e-12) {
        ld mid = (l + r)/ (ld) 2; // guess on a

        ld expon = d / ((ld) 2 * mid); 
        ld eq = (mid * (pow(e, expon) + pow(e, -expon)) / (ld) 2) - mid - s;    // apparently a decreasing function

        //cout << setprecision(10) << "mid: " << mid << " rhs: " << eq << endl;

        if (eq > 0) {
            a = mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    //cout << "a: " << a << " d: " << d << endl;

    ld expon = d / ((ld) 2 * a); 
    ld ans = (ld) 2 * a * ((pow(e, expon) - pow(e, -expon)) / (ld) 2);

    cout << setprecision(10) << ans << endl;

    return 0;
}
