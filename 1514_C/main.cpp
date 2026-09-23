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

    // if gcd (n, x) != 1, then x shares a prime factor with n
    // so product = x * ... shares a prime factor with n
    //  gcd (product, n) >= p > 1

    // but we want product = 1 + tn, and gcd (1 + tn, n) = 1
    // so a product that is not coprime to n, can not be congruent to 1 (mod n)

    int n; cin >> n;

    vector<int> ans;
    ll prod = 1;
    for (int i = 0; i < n; i++) {
        if (gcd(i, n) == 1) {
            ans.push_back(i);
            prod *= i;
            prod %= n;
        }
    }

    if (prod % n == 1) {
        cout << ans.size() << endl;
        print(ans);
    } else {
        cout << ans.size() - 1 << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == prod) {
                continue;
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
