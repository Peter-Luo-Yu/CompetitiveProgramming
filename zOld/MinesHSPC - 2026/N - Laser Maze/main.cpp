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

    int n, m; cin >> n >> m;
    vector<vector<char>> grid (n, vector<char> (m));

    int r, c = 0; cin >> r; r--;
    char dir = 'r';

    //cout << r << " " << c << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    

    while (r >= 0 && c >= 0 && r < n && c < m) {
        if (grid[r][c] == '*') {
            if (dir == 'r') {
                c++;
            }
            else if (dir == 'l') {
                c--;
            }
            else if (dir == 'd') {
                r++;
            }
            else {
                r--;
            }
        } 
        else if (grid[r][c] == '/') {
            if (dir == 'r') {
                dir = 'u';
                r--;
            }
            else if (dir == 'l') {
                dir = 'd';
                r++;
            }
            else if (dir == 'd') {
                dir = 'l';
                c--;
            }
            else {
                dir = 'r';
                c++;
            }
        } 
        else { // grid rc is '\'
            if (dir == 'r') {
                dir = 'd';
                r++;
            }
            else if (dir == 'l') {
                dir = 'u';
                r--;
            }
            else if (dir == 'd') {
                dir = 'r';
                c++;
            }
            else {
                dir = 'l';
                c--;
            }
        }
        //cout << "r: " << r << " c: " << c << " dir: " << dir << endl;
    }

    if (dir == 'r') {
        cout << "RIGHT" << endl;
        cout << r + 1 << endl;
    }
    else if (dir == 'l') {
        cout << "LEFT" << endl;
        cout << r + 1 << endl;
    }
    else if (dir == 'd') {
        cout << "BOTTOM" << endl;
        cout << c + 1 << endl;
    }
    else {
        cout << "TOP" << endl;
        cout << c + 1 << endl;
    }


    return 0;
}
