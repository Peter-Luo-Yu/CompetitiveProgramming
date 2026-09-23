#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++){
        string result = "";
        char signal;
        for(int j = 0; j < n; j++){
            cin >> signal;
            for (int a = 0; a < k; a++){
                result += signal;
            }
        }
        for (int b = 0; b < k; b++){
            cout << result << endl;
        }   
    }

    return 0;
}