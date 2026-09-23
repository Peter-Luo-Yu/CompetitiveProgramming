#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
    freopen("measurement.in" , "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n;
    cin >> n;

    int a[n]; 
    int c[n];
    string b[n];

    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            int t;
            string temp;
            if (a[i] > a[j]){
                t = a[j];
                a[j] = a[i];
                a[i] = t;

                t = c[j];
                c[j] = c[i];
                c[i] = t;

                temp = b[j];
                b[j] = b[i];
                b[i] = temp;

            }
        }
    }

    int count = 0;

    vector<char> winners = {'b', 'e', 'm'};
    vector<int> scores = {7,7,7};

    for (int i = 0; i < n; i++){

        if (b[i] == "Bessie"){
            scores[0] += c[i];
        }
        else if (b[i] == "Elsie"){
            scores[1] += c[i];
        }
        else if (b[i] == "Mildred"){
            scores[2] += c[i];
        }

        vector<char> max = winners;  // temp

        if (scores[0] >= scores[1] && scores[0] >= scores[2]){
            max[0] = 'b';
        } else{
            max[0] = 'n';
        }
        if (scores[1] >= scores[2] && scores[1] >= scores[0]){
            max[1] = 'e';
        } else{
            max[1] = 'n';
        }
        if (scores[2] >= scores[1] && scores[2] >= scores[0]){
            max[2] = 'm';
        }else{
            max[2] = 'n';
        }

        if (winners[0] != max[0] || winners[1] != max[1]|| winners[2] != max[2]){
            count++;
        } 

        for (int i = 0; i < 3; i++){
            winners[i] = max[i];
        }


    }
    
    for (int i = 0; i < n; i++){
        // cout << a[i] << " " << b[i] << " " << c[i] << endl;
        
    }
    cout << count << endl;
}