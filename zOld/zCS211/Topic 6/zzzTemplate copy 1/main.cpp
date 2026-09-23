#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int n;
vector<int> arr;

vector<int> perm;

void recurse () {
    if (perm.size() == arr.size()) {
        print(perm);
        return;
    } 

    for (int i = 0; i < 2; i++) {
        perm.push_back(i);
        recurse();
        perm.pop_back();
    }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s = "-1";
    while (s != "0") {
        getline(cin, s);
        if (s == "0") {
            break;
        }

        n = -1; 
        arr = vector<int> ();
        int prev = -1;
        for (int i = 0; i < s.length(); i++) {
            int val;
            if (s[i] == ' ') {
                val = stoi(s.substr(prev + 1, i - prev));
                if (n == -1) {
                    n = val;
                } else {
                    arr.push_back(val);
                }
                prev = i;
            }
        }
        arr.push_back(stoi(s.substr(prev + 1)));

        
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }        

        //print(arr); cout << "sum: " << sum << endl;

        // dp[i][j]: i = sum, j = using first j elements
        vector<vector<bool>> dp (2 * sum + 1, vector<bool> (arr.size() + 1));
        int zero = sum; // the offset

        dp[zero][0] = true;
        for (int j = 1; j <= arr.size(); j++) {
            for (int i = -sum; i <= sum; i++) {

                // check if sum - (arr in jth) pos was already made
                // now you can make sum with perv sum + (arr in jth)
                
                if ((i - arr[j - 1] >= -sum) && (i - arr[j - 1] <= sum)) {
                    if (dp[zero + i - arr[j - 1]][j - 1] == true) {
                        dp[zero + i][j] = true;
                    }
                } 

                if ((i + arr[j - 1] >= -sum) && (i + arr[j - 1] <= sum)) {
                    if (dp[zero + i + arr[j - 1]][j - 1] == true) {
                        dp[zero + i][j] = true;
                    }
                }
            
                // if you can make sum before, 
                // you still can make it now by not adding the current element
                //if (dp[i][j - 1] == true) { 
                //    dp[i][j] = true;
                //}
            }
        }

        //print2d(dp); cout << "-----------" << endl;

        int diff = 0;
        for (int i = zero; i < dp.size(); i++) {
            if (dp[i][arr.size()] == 1) {
                diff = i;
                break;
            }
        }
        diff -= zero;

        // a + b = sum, a - b = diff (assume a is bigger than b)
        //cout << diff << endl;

        int a = (sum + diff) / 2;
        int b = sum - a;

        cout << a << " " << b << endl;
    }

    
    
    return 0;
}
