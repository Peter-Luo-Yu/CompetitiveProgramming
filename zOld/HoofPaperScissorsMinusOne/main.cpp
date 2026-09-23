#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

void print (vector<int> list){
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    } cout << endl;
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<char>> arr (n, vector<char> (n));

    for (int i = 0; i < n; i++){
        string f; cin >> f;

        for (int j = 0; j < f.length(); j++){
            arr[i][j] = f[j];
        }
    }

    for (int i = 0; i < m; i++){
        int s1, s2; cin >> s1 >> s2; 

        int count = 0;

        bool r1, r2;

        for (int i = 0; i < n; i++){
            r1 = false; r2 = false;

            if (arr[i][s1-1] == 'W' || arr[s1-1][i] == 'L'){ // if i beats s1 or s1 loses to i
                r1 = true;
            }
            if (arr[i][s2-1] == 'W' || arr[s2-1][i] == 'L'){
                r2 = true;
            }   
            if (r1 && r2){
                count++;
            }
        }

        cout << n*n - (n-count) * (n-count) << endl;

    }
   
    return 0;
}