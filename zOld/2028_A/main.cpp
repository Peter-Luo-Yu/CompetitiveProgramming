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
        int n, a, b; cin >> n >> a >> b;

        vector<char> order (n);
        for (int i = 0; i < n; i++) {cin >> order[i];}

        int x = 0, y = 0;
        int cur = 0;
        bool found = false;
        while (cur < 2000){
            if (order[cur % n] == 'N'){
                y++;
            }
            else if (order[cur % n] == 'E'){
                x++;
            }
            else if (order[cur % n] == 'S'){
                y--;
            }
            else if (order[cur % n] == 'W'){
                x--;
            }
            //cout << "x: " << x << " y: " << y << endl;
             
            if (x == a && y == b){
                cout << "YES" << endl;
                found = true;
                break;
            }
            cur++; 
        }

        if (!found){
            cout << "NO" << endl;
        }   


    }

    return 0;
}