/*
ID: peter.I4
LANG: C++
TASK: beads
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n; cin >> n;
    string s; cin >> s;

    vector<char> arr (n); for (int i = 0; i < n; i++) {arr[i] = s[i];}

    int count = 0;
    
    for (int i = 0; i < n; i++){
        // include arr[i] in the right group
        int broken_idx;
        char last_bead = ' '; int right = 0; 

        for (int j = i; j < i+n; j++){
            //cout << arr[j % n] << " " << last_bead << " " << right << endl;

            broken_idx = j;
        
            if (last_bead == ' '){
                last_bead = arr[j % n];
                right++;
            }
            else if (last_bead == 'w'){
                if (arr[j % n] == 'w'){
                    right++;
                } else {
                    last_bead = arr[j % n];
                    right++;
                }
            } else {
                if (arr[j % n] != last_bead && arr[j % n] != 'w'){
                    break;
                } else {
                    right++;
                }
            }
        }

        broken_idx %= n;
        //cout << "broken: " << broken_idx << " " << endl;
        //cout << "------" << endl;

        last_bead = ' '; int left = 0; 
        int j = (i + n - 1) % n;
        
        while (j != broken_idx){
        
            //cout << "j: " << j << " " << arr[j % n] << " " << last_bead << " " << left << endl;

            if (last_bead == ' '){
                last_bead = arr[j % n];
                left++;
            }
            else if (last_bead == 'w'){
                if (arr[j % n] == 'w'){
                    left++;
                } else {
                    last_bead = arr[j % n];
                    left++;
                }
            } else {
                if (arr[j % n] != last_bead && arr[j % n] != 'w'){
                    break;
                } else {
                    left++;
                }
            }

            j = (j - 1 + n) % n;
        }
        //cout << "last j: "<< j << " cur left: " << left << " cur right: " << right << endl;
        if ((arr[j] == 'w' || arr[j] == last_bead) && right != n){
            left++;
        }

        count = max (count, right + left);
        //cout << "ans: " << right + left << endl;

        //cout << "----------------------" << endl;
    } 

    cout << count << endl;

    return 0;
}