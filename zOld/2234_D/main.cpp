#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;

        string s1, s2; cin >> s1 >> s2;

        vector<int> a(n), b(n), c(n);
        
        for (int i = 0; i < n; i++) {
            a[i] = s1[i] - '0';
            b[i] = s2[i] - '0';

            if ((a[i] == 1 && b[i] == 1) || (a[i] == 0 && b[i] == 0)) {
                c[i] = 0;
            } else {
                c[i] = 1;
            }
        }

        ll A0 = 0, A1 = 0, B0 = 0, B1 = 0, C0 = 0, C1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                A1++;
            } else {
                A0++;
            }
            if (b[i] == 1) {
                B1++;
            } else {
                B0++;
            }
            if (c[i] == 1) {
                C1++;
            } else {
                C0++;
            }
        }

        //cout << A0 << " " << A1 << endl;
        //cout << B0 << " " << B1 << endl;
        //cout << C0 << " " << C1 << endl;

        ll sum = A0 * A1 + B0 * B1 + C0 * C1;

        // 2 ^ odd + 1 is div by 3
        if (k % 2 == 1) {
            ll amt = ((1LL << k) + 1LL) / 3LL;
            //cout << "amt: " << amt << endl;

            ll ans = sum * amt;
            
            cout << ans << endl;
        } 

        // 2 ^ even + 1 is always 2 mod 3
        else {
            ll amt = ((1LL << k) + 1LL) / 3LL;
            //cout << "amt: " << amt << endl;

            ll ans = sum * amt;

            ans += (A0 * A1 + B0 * B1);
            
            cout << ans << endl;
        }

        //space;

    }
    


    return 0;
}
