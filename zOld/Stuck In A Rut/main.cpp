#include<vector>
#include<iostream>

using namespace std;

int main() {
    freopen("rut.in", "r", stdin);
    freopen("rut.out", "w", stdout);

    int n;
    cin >> n;

    string dir[n];
    int x[n], y[n];

    for (int i = 0; i < n; i++){
        cin >> dir[i] >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++){
        cout << dir[i] << x[i] << y[i];
    }

    
    
    




    /*
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[i].size(); j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    } */
}