#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

vector<vector<char>> board (8, vector<char> (8));

vector<bool>row_taken (8);

vector<bool> diag1 (15);    // top left to bottom right
vector<bool> diag2 (15);    // top right to bottom left


int valid = 0;


void search (int c){    // the column increments
    if (c == 8){
        valid++;
        return;
    }

    for (int r = 0; r < 8; r++){  // permutations for each row
        if (board[r][c] == '.' && !row_taken[r] && !diag1[r+c] && !diag2[r-c+8-1]){
            row_taken[r] = diag1[r+c] = diag2[r-c+8-1] = true;
            search (c + 1);
            row_taken[r] = diag1[r+c] = diag2[r-c+8-1] = false;
        }
    }
}



int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> board[i][j];
        }
    }

    search(0);

    cout << valid << endl;
    /*
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    return 0;
}