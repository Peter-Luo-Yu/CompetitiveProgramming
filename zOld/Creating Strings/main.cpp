#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string n; cin >> n;
    vector<char> data;

    vector<string> results; 

    for (int i = 0; i < n.length(); i++){
        data.push_back(n[i]);
    }

    sort(data.begin(), data.end());

    do {
        string result = "";
        for (int i = 0; i < data.size(); i++){
            result += data[i];
        }
        results.push_back(result);
    } while (next_permutation(data.begin(), data.end()));

    sort (results.begin(), results.end());


    cout << results.size() << "\n";
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << "\n";
    }


    /*
    for (int i = 0; i < data.size(); i++){
        cout << data[i] << " "; 
    }
    */

    return 0;
}