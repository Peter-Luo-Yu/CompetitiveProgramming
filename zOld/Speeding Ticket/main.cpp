#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> road (n, vector<int>(2));
    vector<vector<int>> bessie (m, vector<int>(2));

    for (int i = 0; i < n; i++){
        int seg, speed;
        cin >> seg >> speed;

        if (i == 0){ 
            road[i][0] = seg;
            road[i][1] = speed;
        }
        else{
            road[i][0] = road[i-1][0] + seg;
            road[i][1] = speed;
        }
    }
    for (int i = 0; i < m; i++){
        int seg, speed;
        cin >> seg >> speed;

        if (i == 0){
            bessie[i][0] = seg;
            bessie[i][1] = speed;
        }
        else{
            bessie[i][0] = bessie[i-1][0] + seg;
            bessie[i][1] = speed;
        }
       
    }

    int max = 0;

    for (int i = 0; i < 100; i++){ // can just brute force this
        int speed_limit = 0, bessie_speed = 0;
        int delta;
        
        for(int j = 0; j < road.size(); j++){
            if (j == 0){
                if (i+1 <= road[j][0]){
                    speed_limit = road[j][1];
                    break;
                }
            } else {
                if (i+1 <= road[j][0] && i+1 > road[j-1][0]){
                    speed_limit = road[j][1];
                    break;
                }
            }            
        }
        for(int j = 0; j < bessie.size(); j++){
            if (j == 0){
                if (i+1 <= bessie[j][0]){
                    bessie_speed = bessie[j][1];
                    break;
                }
            } else {
                if (i+1 <= bessie[j][0] && i+1 > bessie[j-1][0]){
                    bessie_speed = bessie[j][1];
                    break;
                }
            }     
        }
        delta = bessie_speed - speed_limit;
      //  cout << delta << " " << bessie_speed << " " << speed_limit << endl;

        if (delta > max){
            max = delta;
        }
    }
    cout << max << endl;

    /*
    for (int i = 0; i < road.size(); i++){
        for (int j = 0; j < road[i].size(); j++){
            cout << road[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < bessie.size(); i++){
        for (int j = 0; j < bessie[i].size(); j++){
            cout << bessie[i][j] << " ";
        }
        cout << endl;
    } */

    return 0;
}