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

        vector<int> arr (n); for (int i = 0; i < n; i++) {cin >> arr[i];}

        bool failed = false;
        for (int i = 1; i < n; i++){
            if (abs(arr[i] - arr[i - 1]) != 5 && abs(arr[i] - arr[i - 1]) != 7){
                failed = true;
                break;
            }
        }

        if (failed){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    

    return 0;
}