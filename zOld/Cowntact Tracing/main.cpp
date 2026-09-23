#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int N, T; cin >> N >> T; 
    string final_pos; cin >> final_pos;

    vector<int> end (final_pos.size());

    for (int i = 0; i < final_pos.size(); i++){
        char letter = final_pos[i];
        int val = atoi(&letter);
        end[i] = val;
    }

    vector<vector<int>> data (T, vector<int> (3));
    for (int i = 0; i < T; i++){
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    sort (data.begin(), data.end());        // already sorts by time since t is first


    // find x, find the number of possible candidates


    vector<int> candidates (N, 0);
    int x = 0, maxK = 0, minK = 999999;
    vector<int> success_tracker (N, 0); // so we don't overcount x! i'm looping the same x for all k's

    for (int i = 0; i < N; i++){            // the (infected) cow id is i+1

        if (end[i] == 1){                   // candidates must be infected at the end
                     
            for (int k = 0; k < T+1; k++){  // for each value of k, simulate

                vector<int> tracker (N, 0); // must track number of times a cow infected another cow, up to K times

                vector<int> infected (N, 0); // simulator tracker, 0 = fine, 1 = infected

                infected[i] = 1; // patient 0

                for (int j = 0; j < T; j++){  // simulating: all interactions
                    if (infected[data[j][1] - 1] == 1 && infected[data[j][2] - 1] == 1){
                        tracker[data[j][1] - 1]++;
                        tracker[data[j][2] - 1]++;
                    }

                    else if (infected[data[j][1] - 1] == 1 && tracker[data[j][1] - 1] < k){ // if a is infected and b is not
                        tracker[data[j][1] - 1]++;
                        if (infected[data[j][2] - 1] == 0){
                            infected[data[j][2] - 1] = 1;
                        }
                        
                    }

                    else if (infected[data[j][2] - 1] == 1 && tracker[data[j][2] - 1] < k){ // other way around
                        tracker[data[j][2] - 1]++;
                        if (infected[data[j][1] - 1] == 0){
                            infected[data[j][1] - 1] = 1;
                        }
                        
                    }

                    

                }

                bool success = true;


                for (int j = 0; j < N; j++) {
                    //cout << infected[j] << " ";

                    if (infected[j] != end[j]){
                        success = false;
                    }
                }
                //cout <<  " "<< success << "\n";

                if (success){
                    minK = min(k , minK);
                    maxK = max(k , maxK);
                    if (success_tracker[i] == 0){
                        x++;
                        success_tracker[i] = 1;
                    }
                    
                }


            }

        }

    }

    if (maxK == T){
        cout << x << " " << minK << " Infinity" << "\n";
    }
    else {
        cout << x << " " << minK << " " << maxK << "\n";
    }
    

    /* 
    for (int i = 0; i < end.size(); i++){
        cout << end[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].size(); j++){
            cout << data[i][j] << " ";
        }
        cout << "\n";
    } */
    
    return 0;
}