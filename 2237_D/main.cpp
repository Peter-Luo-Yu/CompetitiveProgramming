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
        ll n; cin >> n;
        vector<int> arr (n);
        string s; cin >> s;
        for (int i = 0; i < n; i++) arr[i] = s[i] - '0';

        //print(arr);

        ll ans = n * (n + 1) / 2LL;

        // this is the cnt of the prefix % 3, we need the 1 because the
        // loop doesn't actually add this 1 in for p[0] = 0.
        vector<ll> cnt = {1, 0, 0};
        
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                x += 1;
            } else {
                x -= 1;
            }
            x %= 3;
            if (x < 0) {
                x += 3;
            }
            
            cnt[x]++;
        }

        //print(cnt);
        
        // subtracting cnt choose 2
        for (int i = 0; i < 3; i++) {
            ll subtract = cnt[i] * (cnt[i] - 1) / 2LL;
            ans -= subtract;
        }

        // also have to subtract (odd) alternating len >= 3

        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && arr[j + 1] != arr[j]) {
                j++;
            }

            ll L = j - i + 1;

            ll evenEndPt = (L + 2) / 2;
            ll oddEndPt = (L + 1) / 2;

            ll oddAlternating = evenEndPt * oddEndPt;

            ans -= (oddAlternating - L);

            i = j + 1;
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
