#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    bool done = false;
    /*
    for (int i = 0; i < data.size(); i++){
        if (data[i] == 4 || data[i] == 7){
            if (!done){
                cout << "YES" << "\n";
                done = true;
            }
        }
    }*/


    for (int i = 0; i <= 2; i++){
        for (int j = 0; j <= 2; j++){
            for (int k = 0; k <= 2; k++){
                int number = 0;

                if (i == 1){
                    number += (4*100);
                }
                if (i == 2){
                    number += (7*100);
                }
                if (j == 1){
                    number += (4*10);
                }
                if (j == 2){
                    number += (7*10);
                }
                if (k == 1){
                    number += (4);
                }
                if (k == 2){
                    number += (7);
                }
                if (number > n || number == 0){
                    continue;
                }

                if (n % number == 0 && !done){
                    cout << "YES" << "\n";
                    done = true;
                }

            }
        }
    }


    if (!done){
        cout << "NO" << "\n";
    }
    
    return 0;
}