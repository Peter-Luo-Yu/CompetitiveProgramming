#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        vector<int> arr (s.size());
        for (int i = 0; i < s.size(); i++) {
            arr[i] = s[i] - '0';
        }

        for (int i = 1; i < arr.size(); i++) {
            //print(arr);
            //cout << "looking at: " << arr[i] << endl;

            int bestidx = -1;
            for (int j = i - 1; j > i - 10 && j >= 0; j--) {
                if (arr[i] - (i - j) < 1) {
                    break;
                }

                if (arr[i] - (i - j) > arr[j]) {
                    bestidx = j;
                }
            }

            //cout << "bestidx: " << bestidx << endl;
            
            if (bestidx != -1) {
                arr[i] -= (i - bestidx);
                int temp = i;
                while (temp > bestidx) {
                    swap(arr[temp], arr[temp - 1]);
                    temp--;
                }
            }
            

        }

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
        } cout << endl;

        //print(arr); cout << "---------------" << endl;

    }

    
    return 0;
}
