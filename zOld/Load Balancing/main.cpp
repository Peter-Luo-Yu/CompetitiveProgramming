#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int calcQuadrantMax (vector<vector<int>> data, int x, int y){
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

    for (int i = 0; i < data.size(); i++){
        if (data[i][0] > x && data[i][1] > y){
            q1++;
        }
        if (data[i][0] < x && data[i][1] > y){
            q2++;
        }
        if (data[i][0] < x && data[i][1] < y){
            q3++;
        }
        if (data[i][0] > x && data[i][1] < y){
            q4++;
        }
    }
    int temp1 = max(q1, q2);
    int temp2 = max(q3, q4);

    return max(temp1, temp2);
}


int main() {

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B; cin >> N >> B;

    vector<vector<int>> coords (N, vector<int> (2));

    for (int i = 0; i < N; i++){
        cin >> coords[i][0] >> coords[i][1];
    }

    int minimum = 99999999; 

    for (int i = 0; i < N; i++){                // for each point
        int x1, y1;
        // x0 = coords[i][0]; y0 = coords[i][1];
        x1 = coords[i][0] + 1; 
        y1 = coords[i][1] + 1; 
        

        int poss1;
        poss1 = calcQuadrantMax (coords, x1, y1);   

        cout << x1 << " " << y1 << " " << poss1 << "\n";
        

        //cout << poss1 << " " << poss2 << " " << poss3 << " " << poss4 << "\n";

        minimum = min(minimum, poss1);
    }

    cout << minimum << "\n";

    /*
    for (int i = 0; i < coords.size(); i++){
        cout << coords[i][0] << " " << coords[i][1] << "\n";
    } */

    return 0;
}