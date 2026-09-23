#include <iostream>
#include <vector>


using namespace std;

int main () {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; 
    cin >> t; 

    while (t--){            
        int n; 
        cin >> n;

        vector<int> arr (n);
        int Max = 0, Min = 10000;

        for (int i = 0; i < n; i++){
            cin >> arr[i];
            Max = max (Max, arr[i]);
            Min = min (Min, arr[i]);
        }

        /*
        for (auto x : arr){
            cout << x << " ";
        }
        cout << endl;
        */

        cout << (Max - Min) * (n - 1) << endl;
    }   


}

