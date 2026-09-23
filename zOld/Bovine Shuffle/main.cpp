#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> rule (n);
    vector<int> cows (n);   // in final state
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        rule[i] = val;
    }
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        cows[i] = val;
    }

    vector<int> cur = cows;      // is the previous
    vector<int> prev (n);       // is the actuall next
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < n; i++){   
            prev[i] = cur[rule[i]-1];
        }
        cur = prev;
    }
    

    for (int i = 0; i < n; i++){
        cout << prev[i] << endl;
    }

    /*
    for(int j = 0; j < n; j++){
        cout << cows[j] << " " << rule[j] << endl;
    }
    */

    return 0;
}