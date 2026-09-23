#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';


vector<int> spiral (vector<vector<int>> & arr, int start_x, int start_y, int width, int height){
    int x = start_x, y = start_y;
    int m = width, n = height;

    //cout << "called: " << x << " " << y << " " << m << " " << n << endl;

    vector<int> layer;

    for (int j = y; j < y + m; j++){    // move right
        layer.push_back(arr[x][j]);
        //cout << x << " " << j << endl;
    }
    y = y + m - 1;
    
    for (int i = x + 1; i < x + n; i++){    // move down
        layer.push_back(arr[i][y]);
        //cout << i << " " << y << endl;
    }
    x = x + n - 1;
    
    for (int j = y - 1; j >= start_y; j--){   // move left
        layer.push_back(arr[x][j]);
        //cout << x << " " << j << endl;
    }
    y = start_y;
    
    for (int i = x - 1; i >= 1 + start_x; i--){   // move up
        layer.push_back(arr[i][y]);
        //cout << i << " " << y << endl;
    }
    x = start_x;

    return layer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;

        vector<vector<int>> arr (n, vector<int> (m));

        for (int i = 0; i < n; i++){
            string s; cin >> s;
            for (int j = 0; j < m; j++){
                arr[i][j] = s[j] - '0';
            }
        }

        int loops = min(n, m)/2;
        int ans = 0;
        int x = 0, y = 0; 
        int mm = m, nn = n;
        while (loops--){
            vector<int> layer = spiral (arr,x, y, mm, nn);
            
            //cout << "layer: "; print(layer);

            for (int i = 0; i < layer.size(); i++){
                if (layer[i] == 1 && layer[(i+1) % layer.size()] == 5 && layer[(i+2) % layer.size()] == 4 && layer[(i+3) % layer.size()] == 3){
                    ans++;
                }
            }
            
            x++; y++; mm-=2; nn-=2;
        }
        cout << ans << endl;


        /*
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }*/

    }
    

    return 0;
}