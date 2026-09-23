#include <iostream>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test;
    cin >> test;

    string correct = "codeforces";

    for (int i = 0; i < test; i++){
        int count = 0;
        string text;
        cin >> text;
        for (int j = 0; j < 10; j++){
            if (text[j] != correct[j]){
                count++;
            }
        }
        cout << count << endl;
    }
    
    // cout << a << " " << b << endl;
    
    
    return 0;
}