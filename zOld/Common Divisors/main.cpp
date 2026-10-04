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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr (n);

    vector<int> freq (1e6 + 5);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        for (int div = 1; div * div <= arr[i]; div++) {
            // so you find 2 divides 14
            if (arr[i] % div == 0) { 
                freq[div]++;

                // but 7 > sqrt(14) is also a divisor, but we still need to increment 7
                if (div != arr[i] / div) {
                    freq[arr[i] / div]++;
                }
            }
        }
    }

    for (int i = freq.size() - 1; i >= 0; i--) {
        if (freq[i] >= 2) {
            cout << i << endl;
            break;
        }
    }


    //print(freq);


    return 0;
}
