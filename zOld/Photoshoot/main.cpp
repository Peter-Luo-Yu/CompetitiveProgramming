#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    string data; cin >> data;

    int count = 0;
    char current_state = '-';

    for (int i = 0; i < data.size(); i += 2){
        if (data[i] == data[i+1]){  
            continue;
        }

        if (current_state == '-'){
            if (data[i] == 'H' && data[i+1] == 'G'){
                current_state = 'v';
            }
            else {
                current_state = 'x';
            }

            //cout << "initial state: " << current_state << endl;
        } 

        if (current_state == 'v'){      // if the previous is good
            if (data[i] == 'G' && data[i+1] == 'H'){  
                current_state = 'x';
                count++;
            }
        }
        else if (current_state == 'x'){  // if the previous is bad
            if (data[i] == 'H' && data[i+1] == 'G'){
                current_state = 'v';
                count++;
            }
        }
    } 

    if (current_state == 'x'){
        count++;
    } 

    cout << count << endl;

    /*
    for (int i = 0; i < data.size(); i += 2){
        cout << data[i] << " " << data[i+1] << endl;
    } */
    
    return 0;
}