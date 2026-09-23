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
        vector<int> arr (2 * n);
        for (int i = 0; i < 2 * n; i++){cin >> arr[i];}

        int ones = 0;
        for (int i = 0; i < 2 * n; i++){
            if (arr[i] == 1){
                ones++;
            }
        }
        //cout << "ones: " << ones << endl;

        int Max;

        if (ones > n){
            int remain = ones - n;

            Max = n - remain;
        } else {
            Max = ones;
        }

        int Min = ones % 2;

        cout << Min << " " << Max << endl;
    }
    

    return 0;
}