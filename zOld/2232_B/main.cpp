#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr (n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }   
       
        ll sum = 0, h = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                sum += arr[i];
                h = sum;
            } 
            else if (i < n - 1) {
                if (arr[i] > h) {
                    ll diff = arr[i] - h;

                    sum += h;
                    
                    //arr[i] = h;
                    arr[i + 1] += diff;

                } else {
                    sum += arr[i];

                    ll push = sum % (i + 1);
                    h = sum / (i + 1);

                    //arr[i] = h;
                    arr[i + 1] += push;
                }

            } else {
                if (arr[i] > h) {
                    

                } else {
                    sum += arr[i];

                    ll push = sum % (i + 1);
                    h = sum / (i + 1);

                }
            }
            cout << h << " | "; print(arr);

        }

        
        cout << endl;

         


        space;
    }


    return 0;
}
