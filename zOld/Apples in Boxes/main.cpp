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
        ll n, k; cin >> n >> k;

        vector<ll> arr (n);
        ll Min = 1e18, Max = -1;
        ll numMax = 0;
        ll sum = 0;

        for (int i = 0; i < n; i++){
            cin >> arr[i];
            Min = min (Min, arr[i]);
            Max = max (Max, arr[i]);
            sum += arr[i];
        }

        for (int i = 0; i < n; i++){
            if (arr[i] == Max){
                numMax++;
            }
        }

        //cout << numMax << " " << Max << " " << Min << endl;

        // good if Max - Min - 1 <= k

        if (Max - Min - 1 == k && numMax > 1){
            cout << "Jerry" << endl;
        }
        else if (Max - Min - 1 <= k){
            if (sum % 2 == 0){
                cout << "Jerry" << endl;
            }else {
                cout << "Tom" << endl;
            }
        } else {
            cout << "Jerry" << endl;
        }

    }

    return 0;
}