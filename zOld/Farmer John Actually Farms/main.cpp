#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool check(vector<int> & height, vector<int> & cond, int n){
    bool result = true; 

    for (int i = 0; i < n; i++){
        // there needs to be cond[i] plants taller than plant i
        int count = 0;
        for (int j = 0; j < n; j++){
            if (i == j){
                continue;
            }
            if (height[i] < height[j]){
                count++;
            }
        }

        if (count != cond[i]){
            result = false;
            break;
        }
    }

    return result;
}

/*
bool is_impossible(vector<int> & height, vector<int> & growth, vector<int> & cond, int n){
    bool result = true;

    for (int i = 0; i < n-1; i++){
        for (int j = i; j < n; j++){
            if (cond[i] > cond[j]){  // sorted increasing order
                swap(cond[i], cond[j]);
                swap(growth[i], growth[j]);
                swap(height[i], height[j]);
            }
        }
    }
    
    for (int i = 0; i < n-1; i++){
        // cout << "i : " << i << " " << cond[i] << " " << growth[i] << "\n";
        if (growth[i] <= growth[i+1] && height[i] <= height[i+1]){
            result = false;
        }
    }

    return result;
} */

int num_checks(vector<int> & height, vector<int> & growth, int n){
    int max_diff = 0;
    int min_slope_diff = 9999999;
    int num_checks = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < n; j++){
            if (i == j){
                continue;
            }
            if (abs(height[i] - height[j]) > max_diff){
                max_diff = abs(height[i] - height[j]);
            }
            if (abs(growth[i] - growth[j]) < min_slope_diff){
                min_slope_diff = abs(growth[i] - growth[j]);
            }
        }
        num_checks = max(num_checks, (max_diff/min_slope_diff)+1);
    }
    return num_checks;

}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int a = 0; a < t; a++){ 
        int n;
        cin >> n;       //for each test case
        
        int day = 0;

        vector<int> height(n), growth(n), cond(n);   // const, slope, and rank

        for (int i = 0; i < n; i++){  
            cin >> height[i];
        }
        for (int i = 0; i < n; i++){  
            cin >> growth[i];
        }
        for (int i = 0; i < n; i++){  
            cin >> cond[i];
        }
        
        

        /*for (int i = 0; i < n; i++){
            cout << height[i] <<" "<< growth[i] << " "<<cond[i] << "\n";
        } */
        int tries = num_checks(height, growth, n);
        // cout << "tries: " << tries << endl;
        
        bool stopped = false;

        for (int i = 0; i < tries+1; i++) {
            if (!check(height, cond, n)){
                
                for (int i = 0; i < n; i++){
                    height[i] += growth[i];
                }
                day++;
            }
            else{
                stopped = true;
                break;
            }
        }

        if (stopped){
            cout << day << "\n";
        }
        else{
            cout << "-1" << "\n";
        }

    }

    return 0;
}