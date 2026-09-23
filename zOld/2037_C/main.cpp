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

        if (n < 5){
            cout << -1 << endl;
        }
        else if (n == 5){
            cout << "1 3 5 4 2" << endl;
        }
        else if (n == 6){
            cout << "1 3 5 4 2 6" << endl;
        }
        else if (n == 7){
            cout << "1 3 5 7 2 4 6" << endl;
        }
        else {
            if (n % 2 == 0){
                for (int i = n - 1; i >= 1; i-=2){
                    cout << i << " ";
                }
                cout << 8 << " ";
                for (int i = 2; i <= n; i+=2){
                    if (i != 8){
                        cout << i << " ";
                    }
                }
                cout << endl;
            }

            else {
                for (int i = n; i >= 1; i-=2){
                    cout << i << " ";
                }
                cout << 8 << " ";
                for (int i = 2; i <= n; i+=2){
                    if (i != 8){
                        cout << i << " ";
                    }
                }
                cout << endl;
            }
        }


    }
    

    return 0;
}