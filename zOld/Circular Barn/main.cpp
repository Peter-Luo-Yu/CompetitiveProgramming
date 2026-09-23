#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;

    int data[n]; 

    for (int i = 0; i < n; i++){
        cin >> data[i];
    }

    int min_steps = 999999999;

    for (int i = 0; i < n; i++){  // try opening each door
        int steps = 0;      
        for (int j = 0; j < n; j++){
            if ((j - i) >= 0){
                steps += (data[j] * (j-i));
            }
            else{ // j - i < 0
                steps += (data[j] * (n-abs(i-j)));
            }
            
        }
        if (steps < min_steps){   // update the minimum
            min_steps = steps;
        }
    }
    cout << min_steps << endl;
    



    /*
    for (int i : data){
        cout << i << endl; 
    }
    */
    return 0;
}