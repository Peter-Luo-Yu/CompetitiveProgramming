#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<long long> data(n); for (int i = 0; i < n; i++) {cin >> data[i];}
    sort (data.begin(), data.end());


    long long maximum = 0; 
    long long tuition = 0;

    vector<vector<long long>> prices;            // price tracker

    for (int i = 0; i < n-1; i++){
        if (data[i] != data[i+1]){
            long long price = data[i+1];      // find the next price cows are willing to pay

            long long profit = (data.size() - i - 1) * price;

            if (maximum < profit){
                maximum = profit;
                prices.push_back({profit, price});
            }
            
        }
    }

    for (int i = 0; i < prices.size(); i++){
        if (prices[i][0] == maximum){
            tuition = prices[i][1];
            break;
        }
    }
    

    cout << maximum << " " << tuition << "\n";
    
    return 0;
}