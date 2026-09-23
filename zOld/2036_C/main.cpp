#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int check (string &s, int pos){
    // we define position as the starting point
    if (pos < 0 || pos + 3 > s.length() - 1) {
        return 0;
    }

    if (s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0'){
        return 1;
    } else {
        return 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int count = 0;
        for (int i = 0; i < s.length(); i++){
            count += check (s, i);
        }

        //cout << "initial: " << count << endl;
        
        int n; cin >> n;
        //check before - update - check after
        for (int i = 0; i < n; i++){
            int a; char b; cin >> a >> b;  // a is the pos, b is the replacement
            a--;

            int before = 0, after = 0;

            for (int j = a - 3; j <= a; j++){
                before += check (s, j);
            }

            s[a] = b;

            for (int j = a - 3; j <= a; j++){
                after += check (s, j);
            }
            
            //cout << "a: " << a << " b: " << b << endl;
            //print(arr);
            //cout << "before: " << before << " after: " << after << endl;

            count += (after - before);

            if (count > 0){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    

    return 0;
}