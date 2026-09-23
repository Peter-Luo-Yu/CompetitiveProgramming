#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<char> data(n); for (int i = 0; i < n; i++) {cin >> data[i];}

    int cur_index = 0;
    int mn = 0, mx = 0;

    while (cur_index < n){
        if (data[cur_index] == 'F'){
            cur_index++;
            continue;
        }

        int next_index = cur_index + 1;

        while (next_index < n && data[next_index] == 'F'){    
            next_index++;
        }
        if (next_index == n){
            break;
        } 

        int numF = next_index - cur_index - 1;

        //cout << "cur: " << cur_index << " next: " << next_index << " F-block: " << numF << endl;

        if (data[cur_index] == data[next_index]){
            int length = numF + 2;
            if (numF % 2 == 0){
                mn += 1;
            } else {
                mn += 0;
            }
            mx += length - 1;
        } else {
            int length = numF + 2;
            if (numF % 2 == 0){
                mn += 0;
            } else {
                mn += 1;
            }
            mx += length - 2;
        }

        cur_index = next_index;
    }

    int num_beginning_F = 0;
    while (data[num_beginning_F] == 'F' && num_beginning_F < n){
        num_beginning_F++;
    }
    int num_ending_F = 0;
    while (data[n - 1 - num_ending_F] == 'F' && num_ending_F < n){
        num_ending_F++;
    }

    if (num_beginning_F == n){
        mn = 0;
        mx = n - 1;
    } else {
        //the min doesn't change because we FFFB or BFFF can alternate
        mx += num_beginning_F;
        mx += num_ending_F;
    }

    vector<int> poss;
    if (num_beginning_F > 0 || num_ending_F > 0){
        for (int i = mn; i <= mx; i++){
            poss.push_back(i);
        }
    } else {
        for (int i = mn; i <= mx; i = i+2){
            poss.push_back(i);
        }
    }

    cout << poss.size() << endl;
    for (int i = 0; i < poss.size(); i++){
        cout << poss[i] << endl;
    }

}