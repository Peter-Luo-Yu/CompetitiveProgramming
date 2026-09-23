#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, x; cin >> n >> x;
    vector<pair<int, int>> arr (n);
    for (int i = 0; i < n; i++){
        int val; cin >> val;
        arr[i].first = val;
        arr[i].second = i + 1;
    }

    sort (arr.begin(), arr.end());
    
    /*
    for (int i = 0; i < n; i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }*/

    
    int l = 0, r = n - 1;

    bool found = false;
    while (l < r){
        if (arr[l].first + arr[r].first > x){
            r--;
        }   
        else if (arr[l].first + arr[r].first < x){
            l++;
        }
        else if (arr[l].first + arr[r].first == x){
            cout << arr[l].second << " " << arr[r].second << endl;
            found = true;
            break;
        }
    }

    if (!found){
        cout << "IMPOSSIBLE" << endl;
    }
    

    return 0;
}