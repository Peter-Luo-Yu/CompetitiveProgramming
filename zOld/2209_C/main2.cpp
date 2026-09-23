#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--)  {
        int n; cin >> n;

        vector<int> a(n);


        int ops = 0;
        int idx = 0;
        while (ops < n) {
            cout << "?" << " " << idx + 1 << " " << idx + 2 << endl;
            cout.flush();

            int res;
            cin >> res;

            if (res == 0) {
                a[ops] = 0; 
            } else if (res == 1) {
                a[ops] = 1;
            }

            idx += 2;
            ops += 1;
        }
        
        bool done = false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cout << "! " << i * 2 + 1 << endl;
                cout.flush();
                done = true;
                break;
            }
        }

        if (done) continue;

        int response;
        cout << "? 2 3" << endl;
        cout.flush();

        cin >> response;

        // we know 1 != 2, so if 2 == 3
        // cases: X 0 0 or 0 X X (not possible)

        if (response == 1) { 
            cout << "! 2" << endl;
            cout.flush();
            
        } else if (response == 0) { // 2 != 3, you still need to check if 1 == 3 or not.
            // cases 0 X 0 or X O Y

            cout << "! 1" << endl;
            cout.flush();
        } 



    }
    
    
    return 0;
}
