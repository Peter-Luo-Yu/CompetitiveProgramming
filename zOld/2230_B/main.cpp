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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        vector<int> arr;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int val = s[i] - '0';
            if (val == 4 || val == 8) {
                ans++;
            } else {
                arr.push_back(val);
            }
        }

        //print(arr);

        int n = arr.size();

        int last2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 2 || arr[i] == 6) {
                last2 = i;
                break;
            }
        }
        int odd = 0;
        for (int i = 0; i < last2; i++) {
            if (arr[i] % 2 == 1) {
                odd++;
            }
        }


        int firstodd = n;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) {
                firstodd = i;
                break;
            }
        }
        int even = 0;
        for (int i = firstodd + 1; i < n; i++) {
            if (arr[i] == 2 || arr[i] == 6) {
                even++;
            }
        }

        cout << "odd: " << odd << " even: " << even << endl;

        ans += min (odd, even);

        cout << ans << endl;


        //space;
    }


    return 0;
}
