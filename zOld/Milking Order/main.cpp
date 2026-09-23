#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

void print(vector<int> order){
    for (int i = 0; i < order.size(); i++){
        cout << "pos: " << i << " cow: " << order[i] << endl;
    }
}

bool check(vector<int> order, vector<int> hierarchy){

    vector<int> tracker (100,-1);      // index = cow-1, element = pos of cow 

    for (int i = 0; i < order.size(); i++){
        if (order[i] > 0) {  // Skip empty positions
            tracker[order[i] - 1] = i;
        }
    }

    //print (tracker);

    for (int i = 0; i < hierarchy.size() - 1; i++){
        if (tracker[hierarchy[i] - 1] > tracker[hierarchy[i+1] - 1]){     
            //cout << hierarchy[i] - 1 << " " << tracker[hierarchy[i] - 1] << " greater " <<  hierarchy[i+1] - 1 << " " <<  tracker[hierarchy[i+1] - 1] << endl;
            return false;
        }
    }

    return true;

}

int main() {

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    vector<int> hierarchy (m);
    for (int i = 0; i < m; i++) {cin >> hierarchy[i];}

    vector<vector<int>> absolute (k, vector<int> (2));
    for (int i = 0; i < k; i++) {cin >> absolute[i][0] >> absolute[i][1];}

    vector<int> temp (n);


    for (int i = 0; i < absolute.size(); i++){
        temp[absolute[i][1] - 1] = absolute[i][0];

        if (absolute[i][0] == 1){
            cout << absolute[i][1] << endl;
            return 0;
        }
    }
    
    int min_pos = 1000;

    //print(temp);

    for (int i = 0; i < n; i++){    // check where to put cow 1
        vector<int> order = temp;

        if (order[i] != 0){     // already taken;
            continue; 
        } 
        order[i] = 1;          

        for (int j = 0; j < hierarchy.size(); j++){
            bool already_in = false;                    // check if it already placed 

            for (int x = 0; x < order.size(); x++){
                if (order[x] == hierarchy[j]){
                    already_in = true;
                    break;
                }
            }
            if (already_in) {continue;}

            for (int x = 0; x < order.size(); x++){     // greedily place everybody
                if (order[x] == 0){
                    order[x] = hierarchy[j];
                    break;
                }
            }
        }

        //cout << "cow1: " << i << " " << endl; print(order); cout << endl;
        
        bool is_valid = check (order, hierarchy);

        if (is_valid){
            //cout << "pos: " << i+1 << " worked" << endl;
            min_pos = min (min_pos, i+1);
        }
        /*
        else {
           cout << "pos: " << i+1 << " failed" << endl;
        }*/

    }
   
    cout << min_pos << endl;

    //for (int i = 0; i < m; i++) {cout << hierarchy[i] << " ";} cout << endl;
    //for (int i = 0; i < k; i++) {cout << absolute[i][0] << " " << absolute[i][1] << endl;}
    
    
    
    return 0;
}