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

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int a, b, c; 
    c = arr[n - 1]/3;
    b = arr[n - 2] - (2*c);
    a = arr[0]/3;

    cout << a << " " << b << " " << c;
    

    return 0;
}