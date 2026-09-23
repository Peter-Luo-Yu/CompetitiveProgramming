#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;        // there are 2*n people

    vector<int> data (2*n); for (int i = 0; i < 2*n; i++){cin >> data[i];}
    sort(data.begin(), data.end());

    int minimum = 999999;

    for (int i = 0; i < 2*n; i++){
        for (int j = i+1; j < 2*n; j++){

            int instability = 0;
            vector<int> temp = data;        // make copy

            temp.erase(temp.begin() + j);                  // must do this one first, j > i
            temp.erase(temp.begin() + i);

            for (int i = 0; i < temp.size()-1; i++){
                instability += abs(temp[i] - temp[i+1]);
                i++;
            }
            
            //cout << instability << endl;

            minimum = min (minimum, instability);
            
        }
    }
    
    cout << minimum << "\n";

    /*
    for (int i = 0; i < 2*n; i++){
        cout << data[i] << " ";
    }*/
    
    return 0;
}