#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M; cin >> N >> M;

    vector<vector<char>> spotty (N, vector<char>(M));
    vector<vector<char>> plain (N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        string data; cin >> data;
        for (int j = 0; j < M; j++){
            spotty[i][j] = data[j];
        }
    }
    for (int i = 0; i < N; i++) {
        string data; cin >> data;
        for (int j = 0; j < M; j++){
            plain[i][j] = data[j];
        }
    }

    int count = 0;

    for (int i = 0; i < M-2; i++){              // looping through all possible combo of 3 positions
        for (int j = i+1; j < M-1; j++){
            for (int k = j+1; k < M; k++){
                /*
                vector<vector<char>> taken (N, (vector<char> (3))); // store the 3 taken "chars"

                for (int a = 0; a < N; a++){    // find the 3 taken chars
                    taken[a][0] = spotty[a][i];
                    taken[a][1] = spotty[a][j];
                    taken[a][2] = spotty[a][k];
                }
                */
                bool failed = false;

                for (int a = 0; a < N; a++){   // compare the sequence of 3 chars for both cow types
                    //cout << spotty[a][i] << " " << spotty[a][j] << " " << spotty[a][k] << "\n";
                    
                    for (int b = 0; b < N; b++){
                        if (spotty[a][i] == plain[b][i] && spotty[a][j] == plain[b][j] && spotty[a][k] == plain[b][k]){
                            failed = true;
                        }
                    }
                    
                    if (failed){
                        break;
                    }

                }
                
                if (!failed){
                    count++;
                }
            }
        }
    }

    cout << count << "\n";


    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            cout << plain[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            cout << spotty[i][j] << " ";
        }
        cout << "\n";
    } */
    
    return 0;
}