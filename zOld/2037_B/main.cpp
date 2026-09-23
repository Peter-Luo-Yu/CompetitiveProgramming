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
        sort (arr.begin(), arr.end());

        int goal = n - 2;

        int l = 0, r = arr.size() - 1;

        while (l < r && arr[l] * arr[r] != goal){
            if (arr[l] * arr[r] < goal){
                l++;
            }
            else if (arr[l] * arr[r] > goal){
                r--;
            }
        }

        cout << arr[l] << " " << arr[r] << endl;
        

    }
    
    

    return 0;
}