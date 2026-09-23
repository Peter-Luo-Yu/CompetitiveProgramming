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
        
        ll sum = 0;
        int num2 = 0, num3 = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
            if (s[i] == '2') {
                num2++;
            }
            if (s[i] == '3') {
                num3++;
            }
        }

        sum %= 9;
        int diff = 9 - sum;
    
        //cout << sum << " " << num2 << " " << num3 << endl;
        //cout << "diff: " << diff << endl;
        
        if (diff == 9) {
            cout << "YES" << endl;
            continue;
        }


        // 2 -> 4 adds 2, 3 -> 9 adds 6
        // 2 - 4 - 6 - 8 - (10) 1 - (12) 3 - (14) 5 - (16) 7
        // (6) 6 - (12) 3 - (18) 9 

        int required = diff;
        if (diff == 1) {
            required = 10;  
        } else if (diff == 3) {
            required = 12;
        } else if (diff == 5) {
            required = 14;
        } else if (diff == 7) {
            required = 16;
        }

        //cout << "required: " << required << endl;
        
        bool failed = false;
        while (required > 0 && (num2 > 0 || num3 > 0)) {
            if (required >= 6 && num3 > 0) {
                required -= 6; num3--; 
            } 
            else if (num2 > 0){
                required -= 2; num2--;
            } else {
                break;
            }
        }
        
        //cout << "required: " << required << endl;

        if (required == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
    
    
    return 0;
}
