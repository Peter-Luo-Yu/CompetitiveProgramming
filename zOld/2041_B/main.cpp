#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    
    while (t--) {
        int b, w; cin >> b >> w;

        int rows = 0;
        int cur_req = 1; 

        while (true) {
            int idx = -1;
            int Min = 999999999;
            int Max = -1;

            if (b <= w) {
                idx = 1;
                Min = b;
                Max = w;
            } else {
                idx = 2;
                Min = w;
                Max = b;
            }

            if (Min >= cur_req) {
                if (idx == 1) { 
                    b -= cur_req;
                }
                else {
                    w -= cur_req;
                }
                //cout << b << " " << w << " " << cur_req << " " << rows << endl;

                cur_req++;
                rows++;
            }
            else if (Max >= cur_req) {
                if (idx == 1) { 
                    w -= cur_req;
                }
                else {
                    b -= cur_req;
                }
                //cout << b << " " << w << " " << cur_req << " " << rows << endl;

                cur_req++;
                rows++;
            }
            else {
                break;
            }
        }

        cout << rows << endl;
    }
    

    return 0;
}