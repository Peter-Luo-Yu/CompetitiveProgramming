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

        if (n % 2 != 0){
            if (n < 27) {
                cout << -1 << endl;
            }
            else {
                cout << "12 1 1 2 2 3 3 4 4 12 5 5 6 6 7 7 8 8 9 9 10 10 13 11 11 12 13 ";
                    //    1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1  2  3  4  5  6  7
                for (int i = 14; i <= n/2; i++){
                    cout << i << " " << i << " ";
                }
            }
        } else {
            for (int i = 1; i <= n/2; i++){
                cout << i << " " << i << " ";
            }
            cout << endl;
        }
    }
    

    return 0;
}