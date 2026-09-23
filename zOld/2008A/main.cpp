#include <iostream>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++){
        int a, b;
        cin >> a >> b;

        if (a % 2 == 0 && b == 0){
            cout << "YES" << endl;
        }
        else if (a == 0 && b % 2 == 0){
            cout << "YES" << endl;
        }
        else if (a % 2 == 0 && b % 2 == 0){
            cout << "YES" << endl;
        }
        else if (a % 2 == 1 && b % 2 == 0 && b != 0){
            cout << "YES" << endl;
        }
        else if (a % 2 == 0 && b % 2 == 1 && a != 0){
            cout << "YES" << endl;
        }   
        else {
            cout << "NO" << endl;
        }
        //cout << a << " " << b << endl;
    }
    
    return 0;
}
