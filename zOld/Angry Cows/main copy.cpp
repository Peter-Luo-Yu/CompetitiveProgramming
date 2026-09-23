#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n; 
    vector<int> cows(n); for (int i = 0; i < n; i++) {cin >> cows[i];} // cows are really hays
    sort (cows.begin(), cows.end());
    
    
    return 0;
}