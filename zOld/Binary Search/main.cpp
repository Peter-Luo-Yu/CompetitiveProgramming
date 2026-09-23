#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

bool check (vector<int> arr, int x){
    int l = 0, r = arr.size() - 1;

    while (l <= r){
        int mid = (l+r)/2;
        if (arr[mid] == x){
            return true;
        }
        if (arr[mid] > x){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;

    vector<int> a (n); 
    for (int i = 0; i < n; i++) {cin >> a[i];}

    for (int i = 0; i < k; i++){
        int val; cin >> val;
        if (check(a, val)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}