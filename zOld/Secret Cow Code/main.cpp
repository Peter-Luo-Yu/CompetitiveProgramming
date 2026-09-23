#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    string s; ll n;
    cin >> s >> n;

    int cur = s.length();

    ll len = cur;

    while (len < n) {
        len *= 2;
    }

    /*
    while (cur < n) {
        string temp = s[s.length() - 1] + s.substr(0, s.length() - 1);
        s = s + temp;

        cur = s.length();

        cout << s << endl;
    } */

    while (n > s.length()) {
        ll half = len/2;

        if (n > half) {
            n -= half;
            if (n == 1) {
                n = half;
            } else {
                n--;
            }
        }

        len = half;
    }
    
    cout << s[n-1] << endl;
    
    

    return 0;
}