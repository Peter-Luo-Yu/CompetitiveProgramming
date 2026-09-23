#include <iostream>
using namespace std;

int main(){

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int swaps;
    cin >> swaps;

    int target[3] = {1,2,3};
    
    int scores[3] = {0,0,0};
    
    
    for (int i = 0; i < swaps; i++){
        int shell1;
        int shell2;
        cin >> shell1;
        cin >> shell2;

        int guess;
        cin >> guess;

        for (int j = 0; j < 3; j++){
            
            if (target[j] == shell1){
                target[j] = shell2;
            }
            else if (target[j] == shell2){
                target[j] = shell1;
            }

            if (target[j] == guess){
                scores[j]++;
            }
            
        }
    }
//    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;

    if (scores[0] > scores[1] && scores[0] > scores[2]){
        cout << scores[0];
    }
    else if (scores[1] > scores[0] && scores[1] > scores[2]){
        cout << scores[1];
    }
    else{
        cout << scores[2];
    } 

    return 0;
}