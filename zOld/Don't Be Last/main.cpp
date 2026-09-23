#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n; cin >> n;
    map<string, int> cows;


    for (int i = 0; i < n; i++){
        string name;
        int milk; 

        cin >> name >> milk;

        cows[name] += milk;
    }


    vector<pair<int, string>> milks;

    for (auto x : cows){
        milks.push_back({x.second, x.first});
    }

    sort(milks.begin(), milks.end());

    int minimum = milks[0].first;
    int k = -1;
    int index;

    for (int i = 0; i < milks.size(); i++){
        if (milks[i].first != minimum){
            k = milks[i].first;
            index = i;
            break;
        }
    }

    int occurences = 0;
    for (int i = 0; i < milks.size(); i++){
        if (milks[i].first == k){
            occurences++;
        }
    }
    
    if(occurences > 1 || k == -1){
        cout << "Tie" << endl;
    } else {
        cout << milks[index].second << endl;
    }
        
    return 0;
}