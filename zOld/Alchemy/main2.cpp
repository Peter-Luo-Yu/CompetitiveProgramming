#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<int> amounts;
map<int, vector<int>> recipes;

void print (vector<int> list){
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    } cout << endl;
}

bool can_make(int x){
    if (x == 1){
        return false;
    }

    int have = 0;           // # of metals we have to make x


    vector<int> metal = recipes[x];      // find the recipe of metal x
    
    for (int i = 0; i < metal.size(); i++){
        if (amounts[metal[i]-1] > 0){
            amounts[metal[i]-1]--;
            have++;
        } 
        else if (can_make(metal[i])) {
            amounts[metal[i]-1]--;
            have++;
        } else {
            break;
        }
    }
    

    if (have == metal.size() && metal.size() > 0){
        amounts[x-1]++;

        /*
        cout << "x: " << x;
        cout << " recipe: "; print(metal);
        cout << "amounts: "; print(amounts);
        cout << "true" << endl; cout << endl;
        */

        return true;

    } else {
        
        /*
        cout << "x: " << x;
        cout << " recipe: "; print(metal);
        cout << "amounts: "; print(amounts);
        cout << "false" << endl; cout << endl;
        */
       
        return false;
    }
}


int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int amount; cin >> amount;
        amounts.push_back(amount);
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++){
        vector<int> recipe;

        int l, m;
        cin >> l >> m;

        for (int j = 0; j < m; j++){
            int val; cin >> val;
            recipe.push_back(val);
        }

        recipes[l] = recipe;

        //cout << "l: " << l << " ";
        //print(recipes[l]);
    }

    while (can_make(n)){
    }
    cout << amounts[n-1] << endl;

    /*
    for (int i = 0; i < n; i++){
        cout << amounts[i] << " ";
    } cout << endl;

    for (int i = 0; i < recipes.size(); i++){
        for (int j = 0; j < recipes[i].size(); j++){
            cout << recipes[i][j] << " ";
        }
        cout << endl;
    } */
    
    return 0;
}