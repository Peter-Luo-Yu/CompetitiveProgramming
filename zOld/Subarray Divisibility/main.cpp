#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<ll> prefix (n+1);
    map<ll, ll> count;

    ll subarrays = 0;

    count[0] = 1;

    for (int i = 0; i < n; i++){
        int val; cin >> val;

        prefix[i+1] = (prefix[i] + val) % n;

        if (prefix[i+1] < 0){
            subarrays += count[prefix[i+1] + n];
            count[prefix[i+1]+n]++;
        } else {
            subarrays += count[prefix[i+1]];
            count[prefix[i+1]]++;
        }   

    }

    //print(prefix);

    cout << subarrays << endl;

    return 0;
}