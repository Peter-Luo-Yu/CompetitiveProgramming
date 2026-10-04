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
        string s; cin >> s;
        vector<int> arr (10);
        map<int, int> freq;
        for (int i = 0; i < s.size(); i++) {
            arr[i] = s[i] - '0';
            freq[arr[i]]++;
        }

        //printP(freq);

        vector<int> ans;

        for (int i = 9; i >= 0; i--) {
            for (auto &x : freq) {
                if (x.first >= i && x.second > 0) {
                   
                    x.second--;
                    ans.push_back(x.first);
                    break;
                
                }
            }
        }


        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;

        //space;
    }
    


    return 0;
}
