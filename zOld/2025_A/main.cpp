#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q; cin >> q;

    while (q--){
        string s,t; cin >> s >> t;

        int len = 0;
        int index = 0;
        while (s[index] == t[index] && index < min(s.length(), t.length())){
            len++, index++;
        }

        if (len > 0){
            cout << (len + 1) + (s.length() - len) + (t.length() - len) << endl;
        } else {
            cout << s.length() + t.length() << endl;
        }
        

    }

    return 0;
}