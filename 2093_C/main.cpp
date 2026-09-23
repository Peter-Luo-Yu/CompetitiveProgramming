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
        int n, k; cin >> n >> k;

        if (n == 1) {

            if (k == 1) {
                cout << "NO" << endl;
            } 
            else {
                int val = 0;
                for (int i = 0; i < k; i++) {
                    val += pow(10, i);
                }

                bool is_prime = true;
                for (int i = 2; i * i <= val; i++) {
                    if (val % i == 0) {
                        is_prime = false;
                    }
                }

                if (is_prime) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }

        }

        else {

            bool is_prime = true;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    is_prime = false;
                }
            }
        
            if (is_prime && k == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }


    return 0;
}
