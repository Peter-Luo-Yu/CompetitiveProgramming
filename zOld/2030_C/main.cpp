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

        string s; cin >> s;

        if (s[0] == '0' && s[s.length() - 1] == '0'){
            bool twoInRow = false;
            int count = 0;
            for (int i = 1; i < s.length() - 1; i++){
                if (s[i] == '1'){
                    count++;
                } else {
                    count = 0;
                }
                if (count == 2){
                    twoInRow = true;
                    break;
                }
            }

            if (twoInRow){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        } else {
            cout << "YES" << endl;
        }
    }
    

    return 0;
}