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
        int n; cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        bool failed = false;
        vector<pair<int, int>> arr (n);
        for (int i = 0; i < n; i++) {
            arr[i].first = a[i];
            arr[i].second = i;
        }
        sort (arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            if (arr[i].first > b[i]) {
                failed = true;
            }
        }
        
        printP(arr);
        
        if (failed) {
            cout << -1 << endl; space;
            continue;
        } 

        vector<int> arrb (n);

        for (int i = 0; i < n; i++) {
            arr[i].first = b[i];
        }
        for (int i = 0; i < n; i++) {
            arrb[arr[i].second] = arr[i].first;
        }

        print(arrb);

        ll ans = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int num = b[i];

            int pos;
            for (int j = 0; j < n; j++) {
                if (arrb[j] == num) {
                    pos = j;
                }
            }
            
            cout << "num: " << num << " pos: " << pos << endl;

            // goal pos is i;

            for (int j = pos; j < i; j++) {
                swap (arrb[j], arrb[j + 1]);
                ans++;
            }
        }

        cout << ans << endl;




        space;

    }


    return 0;
}
