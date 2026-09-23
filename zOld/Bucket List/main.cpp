#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;
    
    vector<vector<int>> cows (n, vector<int>(3));

    //get my data
    for (int i = 0; i < n; i++){
        int start,end,num_buckets;
        cin >> start >> end >> num_buckets;

        cows[i][0] = start;
        cows[i][1] = end;
        cows[i][2] = num_buckets;
    }
    // sort my data, bubble sort
    for (int i = 0; i < cows.size(); i++){
        for (int j = 0; j < cows.size()-1; j++){
            if (cows[j][0] > cows[j+1][0]){
                swap(cows[j], cows[j+1]);
            }
        }
    }

    vector<vector<int>> buckets;
    for(int i = 0; i < cows.size(); i++){
        if (i == 0){
            for (int j = 0; j < cows[0][2]; j++){
                buckets.push_back({cows[0][0], cows[0][1]});
            }
        }    
        else{
            for (int z = 0; z < cows[i][2]; z++){
                bool found = false;
                for (int j = 0; j < buckets.size(); j++){
                    if (buckets[j][1] < cows[i][0]){
                        buckets[j][1] = cows[i][1];
                        found = true;
                        break;
                    }
                }
                if (!found){
                    buckets.push_back({cows[i][0], cows[i][1]});
                }
            }
            

        }

    }
    cout << buckets.size() << endl;

    /*
    for(int i = 0; i < cows.size(); i++){
        for (int j = 0; j < cows.size(); j++){
            cout << cows[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}