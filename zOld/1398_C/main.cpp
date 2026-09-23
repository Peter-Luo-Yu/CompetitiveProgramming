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

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;

        vector<int> a (n);
        for (int i = 0; i < n; i++) {a[i] = s[i] - '0';}

        vector<int> prefix (n + 1);
        for (int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + a[i];
        }

        //print(a);
        //print(prefix);

        map <int, ll> mp;
        for (int i = 0; i < prefix.size(); i++){
            mp[prefix[i] - i]++;
        }

        ll ans = 0;
        for (auto x : mp) {
            //cout << x.first << " " << x.second << endl;
            ans += (x.second) * (x.second - 1) / 2;
        }

        cout << ans << endl;

    }
    

    return 0;
}