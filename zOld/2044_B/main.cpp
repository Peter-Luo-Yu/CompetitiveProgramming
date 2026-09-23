#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        vector<char> temp (s.size());
        for (int i = 0; i < s.size(); i++) {
            temp[i] = s[i];
        }

        reverse(temp.begin(), temp.end());

        //cout << "reversed: "; print(temp);

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 'q') {
                temp[i] = 'p';
            } else if (temp[i] == 'p') {
                temp[i] = 'q';
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i];
        }
        cout << endl;
    }
    

    return 0;
}