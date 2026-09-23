#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string cards; cin >> cards;
        vector<char> arr;
        for (int i = 0; i < cards.length(); i++){
            arr.push_back(cards[i]);
        }
        //print(arr);

        if (arr[0] == 'B' && arr[arr.size() - 1] == 'B'){   // BOB owns 1 and n = gg
            cout << "Bob" << endl;
        } 
        else if (arr[0] == 'A' && arr[arr.size() - 1] == 'A'){
            cout << "Alice" << endl;
        }
        else if (arr[arr.size() - 1] == 'B' && arr[0] == 'A'){  // BOB owns n but not 1
            bool found = false;
            for (int i = 1; i < arr.size() - 1; i++){   // BOB needs to beat the 1st card
                if (arr[i] == 'B'){
                    found = true;
                    break;
                }
            }
            if (found){
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        }
        else if (arr[0] == 'B' && arr[arr.size() - 1] == 'A'){
            if (arr[arr.size() - 2] == 'B'){
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        }
        

    }

    return 0;
}