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

    int a, b; cin >> a >> b; // a is mean, b is median
    vector<int> ans;

    if (a < b) {
        int goal = a * 3 - b;
        //cout << goal << endl;

        int big = b + 1;

        goal -= big;

        int small = goal;

        vector<int> arr = {small, b, big};
        sort (arr.begin(), arr.end());

        cout << 3 << endl;
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        
    } else if (a > b) {
        int goal = a * 3 - b;
        //cout << goal << endl;

        int big = b - 1;

        goal -= big;

        int small = goal;

        vector<int> arr = {small, b, big};
        sort (arr.begin(), arr.end());

        cout << 3 << endl;
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    } else {
        cout << 1 << endl;
        cout << a << endl;
    }
    

    return 0;
}