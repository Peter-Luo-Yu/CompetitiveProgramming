#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void print(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k, t; cin >> n >> k >> t;
    vector<int> order(n); for (int i = 0; i < n; i++) {order[i] = i;}
    vector<int> moves(k); for (int i = 0; i < k; i++) {cin >> moves[i];}

    print(order); cout << "   "; print (moves); cout << endl;

    bool done = false;
    int cycle = 0;

    while (!done){
        vector<int> temp = order;

        for (int i = 1; i < moves.size(); i++){
            order[moves[i]] = temp[moves[i-1]];
        }
        order[moves[0]] = temp[moves[moves.size() - 1]];

        for (int i = 0; i < moves.size(); i++){
            moves[i] = ((moves[i] + 1) % n);
        }

        print(order); cout << "   "; print (moves); cout << endl;
        cycle++;


        done = true;
        for (int i = 0; i < order.size(); i++){
            if (order[i] != i){
                done = false;
            }
        }
    }

    cout << cycle << endl;
    
    
    return 0;
}