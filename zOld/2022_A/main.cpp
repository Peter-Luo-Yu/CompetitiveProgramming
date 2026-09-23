#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n, r; cin >> n >> r;

        int total = 0;

        vector<int> arr (n); for (int i = 0; i < n; i++) {cin >> arr[i]; total += arr[i];}

        sort(arr.begin(), arr.end(), greater<>());

        int num_happy = 0;
        int i = 0;
        while (r > 0 && i < n){
            if (arr[i] % 2 == 0 && arr[i] > 0){
                num_happy+=2; arr[i]-=2; total-=2;
                r--;
            } 
            else if (arr[i] % 2 == 1 && arr[i] > 1){
                num_happy+=2; arr[i]-=2; total-=2;
                r--;
            }
            else {
                i++;
            }
        }

        //print(arr); cout << " r: " << r << endl;
        


        // place 1 person in each remaining row
        // place the remaming people starting from the top, the bottom are happy

        if (r > total){
            num_happy += total;
        }
        else {
            num_happy += (r - (total - r));
        }
        
        

        cout << num_happy << endl;
    }   


    return 0;
}



