#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int r, c; cin >> r >> c;
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;
    //cout << sx << sy << ex << ey << endl;

    vector<vector<int>> maze (r, vector<int> (c));

    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++){
            int val = s[j] - '0';
            maze[i][j] = val;
        }
    }

    int iterations = 10000;
    int x = sx, y = sy; 
    int facing = 1; // facing right

    bool end = false;

    //cout << x << " " << y << endl;
    for (int i = 0; i < iterations; i++){
        //cout << x << " " << y << endl;
        if (x == ex && y == ey){
            end = true;
            break;
        }


        int temp;
        if (facing == 0) {temp = 3;}
        else {temp = facing - 1;}

        if (temp == 0){
            if (x - 1 >= 0 && maze[x-1][y] == 0){
                x = x-1; 
                facing = temp;
                continue;
            }
        }
        else if (temp == 1){
            if (y + 1 < c && maze[x][y + 1] == 0){
                y = y+1;
                facing = temp;
                continue;
            }
        }
        else if (temp == 2){
            if (x + 1 < r && maze[x+1][y] == 0){
                x = x+1;
                facing = temp;
                continue;
            }
        }
        else if (temp == 3){
            if (y - 1 >= 0 && maze[x][y - 1] == 0){
                y = y-1;
                facing = temp;
                continue;
            }
        }

        // move if we can
        if (facing == 0){
            if (x - 1 >= 0 && maze[x-1][y] == 0){
                x = x-1;               
                continue;
            }
        }
        else if (facing == 1){
            if (y + 1 < c && maze[x][y + 1] == 0){
                y = y+1;
                continue;
            }
        }
        else if (facing == 2){
            if (x + 1 < r && maze[x+1][y] == 0){
                x = x+1;
                continue;
            }
        }
        else if (facing == 3){
            if (y - 1 >= 0 && maze[x][y - 1] == 0){
                y = y-1;
                continue;
            }
        }

        facing++;
        facing %= 4;
        
    }

    if (end){
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    /*
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            cout << maze[i][j] << " ";
        } cout << endl;
    }
    */
    return 0;
}