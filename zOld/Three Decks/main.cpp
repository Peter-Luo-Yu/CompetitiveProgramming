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
        int a,b,c; cin >> a >> b >> c;

        vector<int> data = {a,b,c};
        sort (data.begin(), data.end());

        int d1 = data[1] - data[0];
        int d2 = data[2] - data[1];

        if (d1%3 != d2%3 || d1 > d2){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}