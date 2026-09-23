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
        int n, k; cin >> n >> k;

        if (n == 1){
            cout << 1 << endl << 1 << endl;
        }
        else if (k == 1 || k == n){
            cout << - 1 << endl;
        }
        else {
            cout << 3 << endl;
            if (k % 2 == 0){
                cout << 1 << " " << k << " " << k + 1 << endl;
            } else {
                cout << 1 << " " << k - 1 << " " << k + 2 << endl;
            }
        }
    }
    

    return 0;
}