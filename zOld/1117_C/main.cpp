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

    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll len; string s; cin >> len >> s;

    ll U = 0, D = 0, R = 0, L = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') {
            U++;
        } else if (s[i] == 'D') {
            D++;
        } else if (s[i] == 'R') {
            R++;
        } else if (s[i] == 'L') {
            L++;
        }
    }

    ll l = 1, r = 1e18;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2LL; // assume this is the number of days
        //cout << "mid: " << mid << endl;
        ll x = x1, y = y1;

        // simulate where the wind blows
        ll times = mid / s.length();
        x += R * times;
        x -= L * times;
        y += U * times;
        y -= D * times;

        for (int i = 0; i < mid % s.length(); i++) {
            if (s[i] == 'U') {
                y++;
            } else if (s[i] == 'D') {
                y--;
            } else if (s[i] == 'R') {
                x++;
            } else if (s[i] == 'L') {
                x--;
            }
        }
        
        ll dist = abs(x2 - x) + abs(y2 - y);

        if (dist > mid) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }

    cout << ans << endl;
    

    return 0;
}