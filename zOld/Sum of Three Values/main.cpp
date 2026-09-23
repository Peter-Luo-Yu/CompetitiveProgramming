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
    vector<pair<int,int>> arr(n);

    for (int i = 0; i < n; i++){
        int val; cin >> val;
        arr[i].first = val;
        arr[i].second = i + 1;
    }

    sort (arr.begin(), arr.end());

    /*
    for (auto i : arr){
        cout << i.first << " " << i.second << endl;
    }*/

    bool found = false;

    for (int i = 0; i < n; i++){
        int l = 0, r = n-1;
        int target = x - arr[i].first;

        while (l < r){
            
            if (arr[l].first + arr[r].first == target && l != i && r != i && l != r){
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << endl;
                found = true;
                break;
            }
            else if (arr[l].first + arr[r].first > target || r == i){
                r--;
            }
            else if (arr[l].first + arr[r].first < target || l == i){
                l++;
            }

            //cout << l << " " << r << endl; 
        }

        if (found){
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}   