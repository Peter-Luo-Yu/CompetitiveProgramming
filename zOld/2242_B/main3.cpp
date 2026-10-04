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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n), one(n + 1), two(n + 1), three(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 1) {
                one[i + 1] = one[i] + 1;
                two[i + 1] = two[i];
                three[i + 1] = three[i];
            }
            if (arr[i] == 2) {
                one[i + 1] = one[i];
                two[i + 1] = two[i] + 1;
                three[i + 1] = three[i];
            }
            if (arr[i] == 3) {
                one[i + 1] = one[i];
                two[i + 1] = two[i];
                three[i + 1] = three[i] + 1;
            }
        }

        //print(arr); print(one); print(two); print(three);

        // this is the cutoff
        bool good = false;
        for (int i = 1; i < n - 1; i++) {
            int ones = one[i];
            int twothree = two[i] + three[i];

            //cout << "i: " << i << " - " << ones << " " << twothree << endl;
            
            if (ones >= twothree) {
                int tar, gap = n - i, num3;
                if ((n - i) % 2 == 0) {
                    tar = ((i + n) / 2) - 1;  
                    num3 = three[tar + 1] - three[i];

                    if (num3 < gap/2) {
                        good = true;
                    }
                }
                else {
                    tar = (i + n) / 2;
                    num3 = three[tar + 1] - three[i];

                    if (num3 < ((gap/2) + 1)) {
                        good = true;
                    }
                }

                //cout << "idx: " << tar << " gap: " << gap << " three's: " << num3 << endl;
                

            }
   
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
       // space;
        
    }


    return 0;
}
