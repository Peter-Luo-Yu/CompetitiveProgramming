#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input5.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int a, b, c; 
    c = arr[n - 1]/3;
    b = arr[n - 2] - (2*c);
    
    //cout << "c: " << c << " b: " << b << endl;

    if (n == 10){
        a = arr[0]/3;
    } else {
        // assume start is aab
        bool aab = true;

        a = (arr[0] - b)/2;
        vector<int> check = {b+b+a, b+b+b, b+b+c, c+c+a, a+b+c};

        for (int i = 0; i < 5; i++){
            bool found = false;
            for (int j = 0; j < n; j++){
                if (check[i] == arr[j]){
                    //cout << check[i] << " " << arr[j] << endl;
                    found = true;
                }
            }
            if (!found){
                aab = false;
                break;
            }
        }

        bool aac = true;
        if (!aab) {
            a =  (arr[0] - c)/2;
            check = {b+b+a, b+b+b, b+b+c, c+c+a, a+b+c};

            for (int i = 0; i < 5; i++){
                bool found = false;
                for (int j = 0; j < n; j++){
                    if (check[i] == arr[j]){
                        //cout << check[i] << " " << arr[j] << endl;
                        found = true;
                    }
                }
                if (!found){
                    aac = false;
                    break;
                }
            }
        }

        /*
        if (aab){
            cout << "aab" << endl;
        } 
        if (aac && !aab){
            cout << "aac" << endl;
        } */

        if (!aab && !aac){ 
            //cout << "BBA!" << endl;
            a = arr[0] - (2 * b);
        }
    }

    cout << a << " " << b << " " << c;    

    return 0;
}