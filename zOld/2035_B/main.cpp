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
        
        if (n == 1 || n == 3){
            cout << - 1 << endl;
        } else {
            if (n % 2 == 0){
                for (int i = 0; i < n - 2; i++){
                    cout << 3;
                }
                cout << 66 << endl;
            }
            else {
                for (int i = 0; i < n - 4; i++){
                    cout << 3;
                }
                cout << 6366 << endl;
            }
        }
    }
    

    return 0;
}