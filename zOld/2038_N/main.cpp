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
        int a,c; char b;
        cin >> a >> b >> c;

        if (b == '<'){
            if (a < c){
                cout << a << b << c << endl;
            } else if (a > c) {
                cout << a << '>' << c << endl;
            } else {
                cout << a << '=' << c << endl;
            }
        } 
        else if (b == '>'){
            if (a > c){
                cout << a << b << c << endl;
            } else if (a < c) {
                cout << a << '<' << c << endl;
            } else {
                cout << a << '=' << c << endl;
            }
        }
        else {
            if (a == c){
                cout << a << b << c << endl;
            } else {
                cout << a << b << a << endl;
            }
        }
    }
    

    return 0;
}