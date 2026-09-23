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
        vector<int> beauty (n);
        for (int i = 0; i < n; i++){
            cin >> beauty[i];
        }

        vector<int> prefix(n), suffix (n);
        for (int i = 0; i < n; i++){
            prefix[i] = beauty[i] + i;
            suffix[i] = beauty[i] - i;
        }

        //print(beauty); print(prefix); print(suffix); cout << endl;

        // we can simply overwrite the bad prefixes
        for (int i = 0; i < n - 1; i++){
            prefix[i + 1] = max (prefix[i + 1], prefix[i]);
        }
        for (int i = n - 1; i > 0; i--){
            suffix[i - 1] = max(suffix[i - 1], suffix[i]);
        }

        //print(prefix); print(suffix); cout << endl;

        int ans = INT32_MIN;

        for (int i = 1; i < n - 1; i++){
            ans = max (ans, beauty[i] + prefix[i-1] + suffix[i+1]);
        }
        cout << ans << endl;
    }
    

    return 0;
}