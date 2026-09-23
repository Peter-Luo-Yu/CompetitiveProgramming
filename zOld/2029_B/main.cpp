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
        string s, r; cin >> s >> r;

        vector<int> S (n), R (n-1);

        for (int i = 0; i < n; i++){
            S[i] = s[i] - '0';
        }
        for (int i = 0; i < n - 1; i++){
            R[i] = r[i] - '0';
        }


        int num0 = 0, num1 = 0;
        for (int i = 0; i < n; i++){
            if (S[i] == 0){
                num0++;
            } else {
                num1++;
            }
        }

        for (int i = 0; i < n - 2; i++){
            if (R[i] == 0){
                num1--;
            } else {
                num0--;
            }
        }

        if (num0 == 1 && num1 == 1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    

    return 0;
}