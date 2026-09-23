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
        vector<int> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> temp = arr;
        sort (temp.begin(), temp.end());

        int big = temp[temp.size() - 2];

        //cout << "big: " << big << endl;
        //print(arr); space;

        for (int i = 0; i < n; i++) {
            int first = -1, last = -1; 

            for (int j = i; j < i + n; j++) {
                if (arr[j % n] >= big) {
                    first = j % n; break;
                }
            }

            int pos = i - 1;
            if (pos == -1) pos = n - 1;
            for (int j = 0; j < n; j++) {
                //cout << "arr: "; print(arr);
                //cout << "pos: " << pos << " arr: " << arr[pos] << endl;
                if (arr[pos] >= big) {
                    last = pos; break;
                }
                pos--;
                if (pos == -1) {
                    pos = n - 1;
                }
            }

            cout << first << " " << last << endl;
            if (last < first) {
                last += n;
            }

            vector<int> w (2 * n, -1);
            w[i] = 0;
            
            int j = 0;
            int idx = i;
            while (j < n) {
                cout << "idx: " << idx << endl;

                // rising up to the max
                if (idx >= i && idx <= first) {
                    cout << "C1: " << endl;

                    if (arr[idx % n] > w[idx]) {
                        w[idx + 1] = min(arr[idx], big);
                    } else {
                        w[idx + 1] = w[idx];
                    }
                }
                // filling in max, first has filled first + 1, 
                else if (idx > first && idx < last) {
                    cout << "C2: " << endl;

                    w[idx + 1] = big;
                }
                // coming back down to 0
                else {
                    if (idx == i + n - 1) break;

                    w[idx + 1] = min(arr[idx + 1], w[idx]);
                  
                }


                idx++; 
                j++;

                print(w);
            }


            space;

        }

        space;
    }


    return 0;
}
