#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void print (vector<int> data){
    for (int x : data){
        cout << x << " ";
    }cout << endl; 
}

int mex (vector<int> list){
    sort (list.begin(), list.end());

    int mex = 0;

    for (int i = 0; i < list.size(); i++){
        if (list[i] == mex){
            mex++;
        }
    }

    return mex;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> data(n); 
        for (int i = 0; i < n; i++){
            int val; cin >> val;
            data[i] = val;
        }
        
        vector<pair<int, int>> ops;
        
        //cout << "-------test: " << t << endl;
        
        
        if (mex(data) == 0){
            cout << "1" << endl;
            cout << "1" << " " << data.size() << endl;
            continue;
        }

        while (mex(data) != 0){

            //create a positive at the end if there aren't any

            if (data[0] == 0 && data[data.size() - 1] == 0){
                vector<int> temp (data.begin(), data.begin() + 2); 
                //cout << temp[0] << " 2*chosen " << temp[1] << endl;
                int replacement = mex (temp);
                //cout << replacement << endl;

                data.erase(data.begin());
                data[0] = replacement;

                ops.push_back({0, 1});

                //print (data);
            }

            // deal with 1 000 1, but the mex (of everything) isn't already zero
            if (data[0] > 0 && data[data.size() - 1] > 0){
                vector<int> temp (data.begin(), data.begin() + 2); 
                int replacement = mex (temp);

                data.erase(data.begin());
                data[0] = replacement;

                ops.push_back({0, 1});

                //print (data);
            }

            // case like 1 000000
            if (data[0] > 0 && data[data.size() - 1] == 0){
                vector<int> temp (data.begin() + 1, data.end());
                int replacement = mex (temp);

                ops.push_back({1, data.size() - 1});

                data.erase(data.begin() + 1, data.end() - 1);
                data[data.size() - 1] = replacement;

                //print (data);
            }
            // case like 000000 1
            if (data[0] == 0 && data[data.size() - 1] > 0){
                vector<int> temp (data.begin(), data.end() - 1);
                int replacement = mex (temp);

                ops.push_back({0, data.size() - 2});

                data.erase(data.begin() + 1, data.end() - 1);
                data[0] = replacement;

                //print (data);
            }
            
            if (mex(data) == 0){    
                ops.push_back({0, data.size() - 1});
            }

        }
        

        //cout << "ANS: " << endl;
        cout << ops.size() << endl;
        for (int i = 0; i < ops.size(); i++){
            cout << ops[i].first + 1 << " " << ops[i].second + 1 << endl;
        }
    }
    
    return 0;
}