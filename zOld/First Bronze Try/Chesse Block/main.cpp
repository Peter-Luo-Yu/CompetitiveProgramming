#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,q;
    cin >> n >> q;

    vector<vector<int>> data (0, vector<int>(4));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                data.push_back({i,j,k,1});      // 1 for solid, 0 for removed
            }
        }
    }

    
    for (int i = 0; i < q; i++){
        int x,y,z;
        cin >> x >> y >> z;
        
        for (int a = 0; a < data.size(); a++){                    // remove 1 chunk at a time
            if (data[a][0] == x && data[a][1] == y && data[a][2] == z){
                data[a][3] = 0;
            }
        }

        int poss = 0;
        int count1,count2,count3;


        for (int a = 0; a < data.size()-1; a++){
            count1 = 0;                          // for each removed block, the changing variable 
            count2 = 0; 
            count3 = 0;                                         // must range from 0 -> n
            for (int b = a+1; b < data.size(); b++){

                if (data[a][3] == 0 && data[b][3] == 0){
                    if (data[a][0] == data[b][0] && data[a][1] == data[b][1]){          // case 1
                        count3 += data[a][2];
                        count3 += data[b][2]; 
                    }

                    if (data[a][0] == data[b][0] && data[a][2] == data[b][2]){             // 2
                        count2 += data[a][1];
                        count2 += data[b][1]; 
                    }
                        
                    if (data[a][1] == data[b][1] && data[a][2] == data[b][2]){             // 3
                        count1 += data[a][0];
                        count1 += data[b][0]; 
                    }
                }
            }
        //   cout << "counts " << count1 << " " << count2 << " " << count3 << endl;
            if (count1 == n*(n-1)/2){
                poss++;
            }
            if (count2 == n*(n-1)/2){
                poss++;
            }
            if (count3 == n*(n-1)/2){
                poss++;
            }
        }


        cout << poss << endl;

    }

    /*
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].size(); j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}