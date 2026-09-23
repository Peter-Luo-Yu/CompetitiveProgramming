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
        int n; cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ans = -1;
        int l = 1, r = 2 * n;

        while (l <= r) {
            int mid = (l + r) / 2;

            int zero_block = 0, prev = -1; // gets compressed
            int one_block = 0; // valuable so no compression
            
            for (int i = 0; i < n; i++) {
                int top, bot;

                if (a[i] >= mid) {
                    top = 1;
                } else {
                    top = 0;
                }
                if (b[i] >= mid) {
                    bot = 1;
                } else {
                    bot = 0;
                }

                if (top + bot == 1) { // we can ignore 0 1 case, 
                    continue; // because 0 1 combined why any other poss (00 01 10 11) is the same
                }

                if (top + bot == 2) {
                    one_block++;
                    prev = 1;
                }
                else if (top + bot == 0) { // we can compress the 0 blocks with themselves greedily
                    if (prev != 0) {
                        zero_block++;
                        prev = 0;
                    }
                }
            }

            if (one_block > zero_block) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } 

        cout << ans << endl;
    }
    


    return 0;
}
