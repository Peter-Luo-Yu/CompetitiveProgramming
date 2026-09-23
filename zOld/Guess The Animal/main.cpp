#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int N; cin >> N;

    vector<vector<string>> data;

    
    for (int i = 0; i < N; i++){    // copies the data successfully
        vector<string> line;

        string animal; cin >> animal;
        line.push_back(animal);

        int M; cin >> M;
        for (int j = 0; j < M; j++){
            string atr; cin >> atr;
            line.push_back(atr);
        }

        data.push_back(line);
    }

    int max_shared  = 0;

    for (int i = 0; i < data.size()-1; i++) {  // hold one animal constant
        for (int j = i+1; j < data.size(); j++){ // compare everybody else
            int num_shared = 0; 
            for (int a = 1; a < data[i].size(); a++){
                for (int b = 1; b < data[j].size(); b++){

                    if (data[i][a] == data[j][b]){
                        num_shared++;
                    }
                }
            }
            max_shared = max(max_shared, num_shared);
        }
        
    }

    cout << max_shared + 1 << "\n";


    /*
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].size(); j++){
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
    */


    return 0;
}