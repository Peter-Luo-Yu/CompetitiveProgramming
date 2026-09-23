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

    vector<int> arr (100);

    for (int i = 0 ; i < 100; i++){
        cin >> arr[i];
    }

    if (arr[99] % 10 == 0){
        cout << 10 << endl;
    } else {
        cout << arr[99] % 10 << endl;
    }
    

    return 0;
}