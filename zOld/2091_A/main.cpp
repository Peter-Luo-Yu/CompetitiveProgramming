#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        //cout << "test ------ " << t << " size: " << n << endl;

        
        int num_0 = 0, num_1 = 0, num_3 = 0, num_2 = 0, num_5 = 0;
        
        bool found = false;

        for (int i = 0; i < n; i++){
            int num; cin >> num;
            if (num == 0){
                num_0++;
            }
            if (num == 1){
                num_1++;
            }
            if (num == 2){
                num_2++;
            }
            if (num == 3){
                num_3++;
            }
            if (num == 5){
                num_5++;
            }

            //cout << num_0 << " " << num_1 << " " << num_2 << " " << num_3 << " " << num_5 << endl;

            if (found){
                continue;
            }

            if (num_0 >= 3 && num_1 >= 1 && num_2 >= 2 && num_3 >= 1 && num_5 >= 1){
                cout << i+1 << endl;
                found = true;
            }
            
        }

        if (!found){
            cout << "0" << endl;
        }
        
    }

    return 0;
}