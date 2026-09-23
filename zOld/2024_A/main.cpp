#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        if (a >= b){
            cout << a << endl;
        }
        else if (2*a-b > 0){
            cout << 2*a-b << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}