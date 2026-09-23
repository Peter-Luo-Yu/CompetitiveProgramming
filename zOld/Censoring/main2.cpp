#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string S, T;
    cin >> S >> T;

    string result;

    for (char c : S){
        result += c;

        if (result.length() >= T.length() && result.substr(result.length() - T.length(), result.length()) == T){
            result.erase(result.length() - T.length(), result.length());
        }
    }
    cout << result << endl;
}
