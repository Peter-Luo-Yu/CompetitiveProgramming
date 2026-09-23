#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B; cin >> N >> B;

    vector<vector<int>> coords (N, vector<int> (2));

    for (int i = 0; i < N; i++){
        cin >> coords[i][0] >> coords[i][1];
    }

    int minimum = N;

    for (int i = 0; i < N; i++){                  // compare each set of x-coords with all the y-coords
        for (int j = 0; j < N; j++){
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

            int x = coords[i][0] + 1;
            int y = coords[j][1] + 1;

            for (int k = 0; k < N; k++){
                if (coords[k][0] > x && coords[k][1] > y){
                    q1++;
                }
                if (coords[k][0] < x && coords[k][1] > y){
                    q2++;
                }
                if (coords[k][0] < x && coords[k][1] < y){
                    q3++;
                }
                if (coords[k][0] > x && coords[k][1] < y){
                    q4++;
                }
            }

            minimum = min(minimum, max({q1, q2, q3, q4}));

        }
    }
    cout << minimum << "\n";

}