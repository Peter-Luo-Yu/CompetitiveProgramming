#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;

        int start = n-k+1, end = n;
        if (start % 2 == 1 || end % 2 == 1){
            if (((end-start)/2 + 1) % 2 == 0){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (((end-start)/2) % 2 == 0){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}