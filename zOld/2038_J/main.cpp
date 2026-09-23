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

    int n; cin >> n;

    int people = 0; 
    
    for (int i = 0; i < n; i++){
        char val; cin >> val;
        int num; cin >> num;

        if (val == 'P'){
            people += num;
        } else {
            if (num >= people){
                num -= people;
                people = 0;
                if (num >= 1){
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                people -= num;
                cout << "NO" << endl;
            }

        }
    }
    

    return 0;
}