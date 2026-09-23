#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n; cin >> n;
    vector<char> boxes (n);
    for (int i = 0; i < n; i++) {cin >> boxes[i];}

    int min_k = 999999999;

    for (int k = 1; k <= n; k++){   // for each poss of k, check if it works
        
        set<string> poss;
        
        for (int i = 0; i < boxes.size() - k + 1; i++){  // starting point
            string result = "";
            for (int j = i; j < i + k; j++){         // the string
                result += boxes[j];
            }
            poss.insert(result);
            //cout << result << endl;
        }

        //cout << "k: " << k << " poss size: " << poss.size() << endl;

        if (poss.size() == n - k + 1){
            min_k = min(min_k, k);
        }

    }

    //for (int i = 0; i < n; i++) {cout << boxes[i] << " ";}
    cout << min_k << endl;
    
    return 0;
}