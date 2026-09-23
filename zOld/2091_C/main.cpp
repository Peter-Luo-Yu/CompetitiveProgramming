#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        if (n % 2 == 0){
            cout << "-1" << endl;
            continue;
        } else {
            for (int i = 1; i <= n; i += 2){
                cout << i << " ";
            }
            for (int i = 2; i < n; i += 2){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}