#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    
    vector<vector<int>> data(3, vector<int>(2));
    
    for (int i = 0; i < 3; i++){
        int cap;
        int val;
        cin >> cap; 
        cin >> val;
        data[i][0] = cap;
        data[i][1] = val;
    }

    for (int i = 0; i < 100; i++){
        if (i % 3 == 0){   //first to second
            int maximum = data[(i+1)%3][0] - data[(i+1)%3][1];
            int delta = data[i%3][1];
            int final = min(maximum, delta);
            
            data[i%3][1] -= final;
            data[(i+1)%3][1] += final;
        }
        else if(i % 3 == 1){
            int maximum = data[(i+1)%3][0] - data[(i+1)%3][1];
            int delta = data[i%3][1];
            int final = min(maximum, delta);
            
            data[i%3][1] -= final;
            data[(i+1)%3][1] += final;
        }
        else{
            int maximum = data[(i+1)%3][0] - data[(i+1)%3][1];
            int delta = data[i%3][1];
            int final = min(maximum, delta);
            
            data[i%3][1] -= final;
            data[(i+1)%3][1] += final;
        }
    }

    cout << data[0][1] << endl;
    cout << data[1][1] << endl;
    cout << data[2][1] << endl;
    /*
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    } */
    

    return 0;
}