#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    mt19937 rng((uint64_t) new char);
    uniform_int_distribution uni(1,3);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n < 0) return 0;

        int one = 1, two = 2, three = 3;

        cerr << n << endl;

        while (true) {
            cout << "? " << one << " " << two << " " << three << endl;
            cout.flush();

            int ans; cin >> ans;
            if (ans < 0) return 0;
            if (ans == 0) break;

            int swp = uni(rng);

            if (swp == 1) one = ans;
            else if (swp == 2) two = ans;
            else three = ans;
        }


        cout << "! " << one << " " << two << " " << three << endl;
        cout.flush();
    }


    return 0;
}
