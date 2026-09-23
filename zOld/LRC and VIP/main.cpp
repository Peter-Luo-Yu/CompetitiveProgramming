#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--){
        int n; cin >> n;

        vector<int> arr (n); for (int i = 0; i < n; i++){cin >> arr[i];}

        if (n == 2){
            if (arr[0] == arr[1]){
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
                cout << 1 << " " << 2 << endl;
            }
            continue;
        }

        bool found = false;
        int gcd1 = -1, gcd2 = -1;
        int isolated;

        for (int i = 0; i < n; i++){
            gcd1 = arr[i];
            isolated = i;

            for (int j = 0; j < n; j++){
                if (j == i){
                    continue;
                }
                if (gcd2 == -1){
                    gcd2 = arr[j];
                } else {
                    gcd2 = gcd(gcd2, arr[j]);
                }
            }

            if (gcd1 != gcd2){
                found = true;
                break;
            }
        }
        
        if (found){
            cout << "YES" << endl;
            for (int i = 0; i < n; i++){
                if (i == isolated){
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            } cout << endl;
            continue;
        }

        vector<int> final_pos (n, 0);
        
        found = false;

        for (int i = 0; i < n - 1; i++){
            for (int j = i+1; j < n; j++){
                vector<int> idx1 (n, 0), idx2 (n, 0);
                gcd1 = -1, gcd2 = -1;

                idx1[i] = 1, idx1[j] = 1;
                gcd1 = gcd(arr[i], arr[j]);

                for (int k = 0; k < n; k++) {
                    if (idx1[k] == 1){
                        continue;
                    }

                    if (gcd(gcd1, arr[k]) == gcd1){
                        idx1[k] = 1;
                    }
                }

                for (int k = 0; k < n; k++){
                    if (idx1[k] == 1){
                        continue;
                    }

                    if (gcd2 == -1){
                        gcd2 = arr[k];
                    } else {
                        gcd2 = gcd(gcd2, arr[k]);
                    }
                }

                //cout << "gcd1: " << gcd1 << " gcd2: " << gcd2 << endl;

                if (gcd1 != gcd2 && gcd1 != -1 && gcd2 != -1){
                    found = true;

                    final_pos = idx1;

                    break;
                }
            }
            if (found){
                break;
            }
        }
        
        if (found){
            cout << "YES" << endl;
            for (int i = 0; i < n; i++){
                if (final_pos[i] == 0){
                    cout << 1 << " ";
                }
                else {
                    cout << 2 << " ";
                }
            } cout << endl;
        }
        else {
            cout << "NO" << endl;
        }

        //print(final_pos); cout << gcd1 << " " << gcd2 << endl;
        
        /*
        if (!found){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            
            for (int i = 0; i < n; i++){
                if (i == idx1 || i == idx2){
                    cout << 2 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }*/

    }

    
    return 0;
}