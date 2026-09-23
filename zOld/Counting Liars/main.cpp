#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N; cin >> N;

    vector<pair<int, char>> cows;
    for (int i = 0; i < N; i++) {
        char sign; int num;
        cin >> sign >> num;
        cows.push_back({num, sign});
    }
    sort (cows.begin(), cows.end());

    //for (int i = 0; i < N; i++) {cout << cows[i].first << " " << cows[i].second << endl;}

    int min_liars = 999999;

    for (int i = 0; i < cows.size(); i++) { // where Bessie can be
        int Bessie_pos = cows[i].first;
        int liars = 0;

        for (int j = 0; j < cows.size(); j++){
            if (cows[j].second == 'L' && Bessie_pos > cows[j].first){
                liars++;
            }
            if (cows[j].second == 'G' && Bessie_pos < cows[j].first){
                liars++;
            }
        }

        min_liars = min(min_liars, liars);
    }

    cout << min_liars << endl;
    
    return 0;
}