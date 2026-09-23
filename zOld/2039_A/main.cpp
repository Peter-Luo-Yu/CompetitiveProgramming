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

        vector<bool> vis (101);

        int prev = 0;
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= 100; j++){
                if (vis[j] == true) {
                    continue;
                }
                if (j % i == i - 1 && j > prev){
                    vis[j] = true;
                    prev = j;
                    cout << j << " ";
                    break;
                }
            }
        }

        cout << endl;
    }
    

    return 0;
}