#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;

    string a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    /*
    for (int i = 0; i < n; i++){
        cout << a[i] << " " << b[i] << endl;
    }

    cout << "         ";
    for (int i = 97; i < (97+26); i++){
        cout << char(i) << " ";
    }
    cout << endl;
    */

    // remember "a" = 97
    
    vector<int> final (26);
    vector<int> count1 (26);
    vector<int> count2 (26);

    for (int i = 0; i < n; i++){
        fill(count1.begin(), count1.end(), 0);
        fill(count2.begin(), count2.end(), 0);

        int j = 0;
        while (j < a[i].length()){
            count1[a[i][j] - 97]++; 
            j++;
        }           
        while (j >= a[i].length() && j < (a[i].length() + b[i].length())){
            count2[b[i][j-a[i].length()] - 97]++; 
            j++;
        }
        
        /*
        cout << "Count 1: ";
        for (int i = 0; i < final.size(); i++){
            cout << count1[i] << " ";
        }
        cout << endl;
        cout << "Count 2: ";
        for (int i = 0; i < final.size(); i++){
            cout << count2[i] << " ";
        }
        cout << endl;
        */
        //cout << "Final " << i << ": ";
        for (int k = 0; k < 26; k++){
            final[k] += max(count1[k], count2[k]);

            //cout << final[k] << " ";
        }
        //cout << endl;
    }

    
    for (int i = 0; i < final.size(); i++){
        cout << final[i] << endl;
    }
    
    return 0;
}