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

        vector<ll> arr (n);
        for (int i = 0; i < n; i++) {cin >> arr[i];}

        vector<ll> temp = arr;

        reverse (arr.begin(), arr.end());

        vector<ll> prefix (n+1, 0);
        vector<ll> maximum (n+1, 0);

        ll cur_max = -1;

        for (int i = 0; i < arr.size(); i++){
            prefix[i+1] = prefix[i] + arr[i];

            cur_max = max (cur_max, temp[i]);
            maximum[n-i-1] = cur_max;
        }

        //print(arr); print(temp); print(prefix); print(maximum);

        for (int i = 0; i < n; i++){
            cout << prefix[i] + maximum[i] << endl;
        }
    }


    return 0;
}