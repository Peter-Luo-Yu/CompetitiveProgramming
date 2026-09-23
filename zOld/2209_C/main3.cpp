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
        int idx = 2;
        while (ops < n - 1) {
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
        
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 1) {
                cout << "! " << i * 2 + 3 << endl;
                cout.flush();
                done = true;
                break;
            }
        }

        if (done) continue;

        int response1;
        cout << "? 1 3" << endl;
        cout.flush();
        cin >> response1;

        int response2;
        cout << "? 1 4" << endl;
        cout.flush();
        cin >> response2;


        if (response1 == 1 || response2 == 1) {
            cout << "! 1" << endl;
        }
        else {  // we already know there's a 0 in a1 or a2, every pair is different: can't be double 0.

            // c1: a1 = 0, a2 != 0 -> a3, a4 != 0 -> not enough zero's placed. (n - 1 zeros into 2(n - 2) slots)
            // c2: a1 = 0, a2 = 0 -> same as c1 -> not enough zero placed. (n - 1 zeros in 2(n - 2) slots)
            // c3: a1 != 0, a2 = 0 -> a3 could be zero or a4 could also be zero (but not both) -> fine. (n - 2 zeros in 2(n-2) slots) 

            cout << "! 2" << endl;
        }
        
        cout.flush();
    
    }
    
    
    return 0;
}
