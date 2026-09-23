#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input3.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = 10, b = 123, c = 154;
    vector<int> arr  = {a+a+a, a+a+b, a+a+c, b+b+a, b+b+b, b+b+c, c+c+a, c+c+b, c+c+c, a+b+c};
    sort(arr.begin(), arr.end());
    
    print(arr);

    return 0;
}