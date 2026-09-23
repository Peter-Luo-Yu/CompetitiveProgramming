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
        int n, m; cin >> n >> m;

        int Max = 0; 

        for (int i = 0; i < n; i++){
            int val; cin >> val;
            Max = max (Max, val);
        }

        for (int i = 0; i < m; i++){
            char a; cin >> a;
            int l, r; cin >> l >> r;

            if (l <= Max && Max <= r){
                if (a == '+'){
                    Max++;
                }
                else {
                    Max--;
                }
            }

            cout << Max << " ";
        }
        cout << endl;
    }
    
    return 0;
}