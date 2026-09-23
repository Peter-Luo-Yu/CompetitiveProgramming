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


    cout << fixed << setprecision(10);

    int t; cin >> t;
    while (t--){
        ll n, b, c; cin >> n >> b >> c;
        
        if (b == 0){
            if (c >= n){
                cout << n << endl;
            }
            else if (c >= n - 2){
                cout << n - 1 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            if (c >= n){
                cout << n << endl;
            }
            else {
                //cout << "case: ";
                ll left = n - c - 1;
             
                cout << left - (left/b) + c << endl;
            }
        }
    }
    

    return 0;
}