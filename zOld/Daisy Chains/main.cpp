#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    int data[n]; for (int i = 0; i < n; i++) {cin >> data[i];}

    int count = 0; 

    for (int i = 1; i <= n; i++){   // chains of length i -> n
        
        for (int j = 0; j <= n-i; j++){     // beginning at index j -> n - length
            int sum = 0;
            double average = 0;

            for (int z = j; z < j+i; z++){  // the daisy chain itself
                sum += data[z];
            }
            average = (double) sum/i;   
            // cout << average << "\n";

            for (int z = j; z < j+i; z++){  // check if average is contained
                if (data[z] == average){
                    
                    count++;
                    break;
                }
            }
            
        }
        
    }

    cout << count << "\n";

    
    return 0;
}