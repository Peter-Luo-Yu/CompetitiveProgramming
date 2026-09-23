#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> arr = {12,4,21,32,5,51,62,14,3,25,1};

    int n = arr.size();

    print(arr);

    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            int t;

            if (arr[i] > arr[j]){
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;

                print(arr);
            }
        }
    }

    //print(arr);

    return 0;
}