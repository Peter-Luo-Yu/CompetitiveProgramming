#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

long long n;
vector<long long> weights;

vector<long long> subset;

long long total = 0;
long long min_diff = 999999999999;

void process(){
    long long sum = 0;
    for (int i = 0; i < subset.size(); i++){
        //cout << subset[i] << " ";
        sum += subset[i];
    }
    //cout <<  "min_diff: " << abs(sum - (total - sum)) << endl;
    min_diff = min (min_diff, abs(sum - (total-sum)));
}

void search(int i){
    if (i == n){
        process();
    } else {
        search(i+1);
        subset.push_back(weights[i]);
        search(i+1);
        subset.pop_back();
    }

}


int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    weights.assign(n, 0);

    for (int i = 0; i < n; i++) {cin >> weights[i]; total += weights[i];}
    
    search(0);

    cout << min_diff << "\n";

    // for (int i = 0; i < n; i++) {cout << weights[i] << " ";}
    
    return 0;
}