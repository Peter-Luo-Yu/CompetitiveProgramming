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
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        int max_count = 1;
        int cur = 0;
        int val;
        for (int i = 0; i < n; i++){
            if (i == 0){
                val = arr[i];
                cur++;
            }
            else {
                if (arr[i] == val){
                    cur++;
                    max_count = max (max_count, cur);
                }
                else {
                    cur = 1;
                    val = arr[i];
                }
            }
        }

        cout << n - max_count << endl;
    }
    

    return 0;
}