#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x; cout << '\n';

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<char> arr;
    string s; cin >> s;

    for(int i = 0; i < s.length(); i++){
        arr.push_back(s[i]);
    }
    print(arr);

    int n; cin >> n;

    vector<vector<string>> rules;

    while (n--){
        string rule; cin >> rule;

        string left = "", right = "";
        
        int index = 0;
        while (rule[index] != '='){
            left += rule[index];
            index++;
        }
        for (int i = index + 1; i < rule.length(); i++){
            right += rule[i];
        }

        //cout << left << " " << right << endl;
        rules.push_back({left, right});
    }

    int steps = 0;
    int length = arr.size();

    int prev_index = 0;

    for (int t = 0; t < 5000; t++){
        int replac_idx = -1;

        string replac, replacment;

        for (int i = prev_index; i < prev_index + n; i++){
            replac = rules[i % n][0];
            replacment = rules[i % n][1];

            for (int j = 0; j < arr.size() - replac.length(); j++){
                string cur = "";

                for (int k = j; k < j + replac.length(); k++){
                    cur += arr[k];
                }

                if (cur == replac){
                    replac_idx = j;
                }
            }
        }

        prev_index = replac_idx;
            
        cout << "replac: " << replac_idx << " replacment: " << replacment << endl;

        for(int j = replac_idx; j < replac_idx + replac.length(); j++){
            arr.erase(arr.begin() + replac_idx);
        }
        
        cout << "before: "; print(arr);

        int replacment_idx = 0;

        for (int j = replac_idx; j < replac_idx + replacment.length(); j++){
            arr.insert(arr.begin() + j, replacment[replacment_idx]);
            replacment_idx++;
        }

        cout << "after: "; print(arr);
            
    }


    /*
    for (int i = 0; i < rules.size(); i++){
        cout << rules[i][0] << " " << rules[i][1] << endl;
    }*/


    return 0;
}