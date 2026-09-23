#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int r = 0, y = 0;

    for (int k = 0; k < 10; k++){ 
        int n; cin >> n;
    
        vector<int> red_x (n);
        vector<int> red_y (n);
        
        for (int i = 0; i < 2*n; i++){
            int val; cin >> val;
            if (i % 2 == 0){
                red_x[i/2] = val;
            } else {
                red_y[i/2] = val;
            }
        }
        //print(red_x); print(red_y);
        
        int m; cin >> m;
        vector<int> yel_x (m);
        vector<int> yel_y (m);

        for (int i = 0; i < 2*m; i++){
            int val; cin >> val;
            if (i % 2 == 0){
                yel_x[i/2] = val;
            } else {
                yel_y[i/2] = val;
            }
        }
        //print(yel_x); print(yel_y);

        vector<int> dist_r (red_x.size());
        vector<int> dist_y (yel_x.size());

        // button is at (144, 84)
        for (int i = 0; i < red_x.size(); i++){
            int dist = (red_x[i] - 144) * (red_x[i] - 144) + (red_y[i] - 84) * (red_y[i] - 84);
            dist_r[i] = dist;
        }
        for (int i = 0; i < yel_x.size(); i++){
            int dist = (yel_x[i] - 144) * (yel_x[i] - 144) + (yel_y[i] - 84) * (yel_y[i] - 84);
            dist_y[i] = dist;
        }
        sort(dist_r.begin(), dist_r.end());
        sort(dist_y.begin(), dist_y.end());

        if (n == 0 || m == 0){
            if (n == 0){     // red has nothing
                y += m;
            } else {        // yellow has nothing
                r += n;
            }
        }
        else {
            if (dist_r[0] < dist_y[0]){
                int count = 0;
                for (int i = 0; i < dist_r.size(); i++){
                    if (dist_r[i] < dist_y[0]){
                        count++;
                    }
                }
                r += count;
            }
            else {
                int count = 0;
                for (int i = 0; i < dist_y.size(); i++){
                    if (dist_y[i] < dist_r[0]){
                        count++;
                    }
                }
                y += count;
            }
        }
    }

    cout << r << " " << y << endl;

    


    return 0;
}