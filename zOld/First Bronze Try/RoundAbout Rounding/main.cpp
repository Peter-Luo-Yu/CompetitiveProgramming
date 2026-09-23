#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> data(n);

    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        data[i] = val;
    }

    vector<int> count(n,0);

    for (int i = 0; i < data.size(); i++){ // 10^p >= x
        for (int j = 2; j <= data[i]; j++){ 
            int p = -1;       
            for (int x = 0; x < 20; x++){
                if (pow(10,x) >= j){
                    p = x;
                    break;
                }
            }

       //     cout << "p:" << p << " ";
            int value = j;
        //    cout << value << " ";
            vector<int> number (p,0);
            int round;  // bessie is correct
            int chain;  // elsie is wrong 

            if (j >= pow(10,p)/2){
                round = pow(10,p);
            }
            if (j < pow(10,p)/2){
                round = 0;
            }

            for(int k = 0; k < p; k++){    // get the digits, but in reverse order
                number[k] = value % 10;
                value /= 10;
            }
            
            vector<int> temp = number;     // reversed
            for (int k = 0; k < p; k++){
                temp[k] = number[p-k-1];
            }
            number = temp;
            
            for (int z = 0; z < number.size(); z++){  // print out
         //       cout << number[z] << " ";
            }
            
            
            for (int k = p-1; k > 0; k--){
                if (number[k] >= 5){
                    number[k-1]++;
                }
            }
            if (number[0] >= 5 || j == pow(10,p)){
                chain = pow(10,p);
            }
            else{
                chain = 0;
            }
            
         //   cout << "round " << round << " chain " << chain << endl;

            if (round != chain){
                count[i]++;
            }

        }
    
    }
    

    for (int i = 0; i < count.size(); i++){
        cout << count[i] << endl;
    }

    /*
    for(int i = 0; i < n; i++){
        cout << data[i] << endl;
    }
    */

    return 0;
}