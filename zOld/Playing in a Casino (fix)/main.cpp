#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    for (int x = 0; x < t; x++){
        int n, m; cin >> n >> m; // n cards, m #'s on each card
        
        int count = 0;

        vector<vector<int>> data (n, vector<int> (m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> data[i][j];
                //cout << data[i][j] << " ";
            }
            //cout << "\n";
        }

        for (int i = 0; i < n-1; i++){
            int sum = 0; 

            for (int j = i+1; j < n; j++){

                for (int k = 0; k < m; k++){
                    
                    sum += abs(data[i][k] - data[j][k]);

                }
            }

            count += sum;
        }
        cout << count << "\n";
    }




    
    
    return 0;
}