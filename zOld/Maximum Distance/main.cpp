#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    int x[n], y[n];

    for (int i = 0; i < n; i++){
        cin >> x[i]; 
    }
    for (int i = 0; i < n; i++){
        cin >> y[i];
    }

    int max_dist = 0;
    int h, v;
    

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (i == j){
                continue;
            }

            h = abs(x[i] - x[j]);

            v = abs(y[i] - y[j]);

            if ((h*h + v*v) > max_dist){
                max_dist = (h*h + v*v);
            }
            
            // cout << x[i] << " " << x[j] << " " << h << " " << y[i] << " " << y[j] << " " << v << endl;


        }
    }


    cout << max_dist << endl;
    /*
    for (int i = 0; i < n; i++){
        cout << x[i] << " " << y[i] << endl;
    }*/
}