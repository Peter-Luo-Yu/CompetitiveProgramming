#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map> 

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, x; cin >> n >> x;
    
    vector<int> data (n);                      // automatically sorted, and removes duplicates

    for (int i = 0; i < n; i++){
       cin >> data[i];  
    }

    map<int, int> map;                      // wanna store the value itself and the index 

    bool done = false;

    for (int i = 0; i < n; i++) {
        

        if (map.count(x - data[i]) == 1){    // if you a value that sums to x with data[i]
            cout << i+1 << " " << map[x-data[i]] << "\n";
            done = true;
            break;
        }

        map[data[i]] = i+1;                 // must come second so it doesn't use itself twice
    }
    if (!done){
        cout << "IMPOSSIBLE" << "\n";
    }
   
    /*
    for (int i = 0; i < n; i++){
        cout << data[i] << " ";
    }*/
    
    return 0;
}