#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n; cin >> n;
    string a, b; cin >> a >> b;
    string c = "";

    int flips = 0;

    for (int i = 0; i < n - 1; i++){
        if (a[i] == b[i] && a[i+1] != b[i+1]){
            flips++;
        }
    }

    if (a[0] != b[0]){
        flips++;
    }

    cout << flips << endl;
    
    return 0;
}