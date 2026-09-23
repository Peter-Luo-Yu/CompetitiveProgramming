#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<vector<int>>> adam (3, vector<vector<int>> (3, vector<int> (3)));

    for (int i = 0; i < adam.size(); i++){
        for (int j = 0; j < adam[i].size(); j++){
            for (int k = 0; k < adam[i][j].size(); k++){

                cout << adam[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}