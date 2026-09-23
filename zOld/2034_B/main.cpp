#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n, m, k; cin >> n >> m >> k;

        string s; cin >> s;
        vector<int> arr (n);

        for (int i = 0; i < n; i++){
            arr[i] = s[i] - '0';
        }

        vector<int> length, pos, type;

        int prev = arr[0], len = 1;
        for (int i = 1; i < n; i++){
            if (arr[i] == prev){
                len++;
            } else {
                length.push_back(len);
                pos.push_back(i - len);
                type.push_back(prev);

                len = 1; prev = arr[i];
            }
        }
        length.push_back(len);
        pos.push_back(n - len);
        type.push_back(prev);
        pos.push_back(n);

        //cout << "pos:  "; print(pos);
        //cout << "len:  "; print(length);
        //cout << "type: "; print(type);
        

        // m is the tolerance
        // k is the length that gets filled

        int end = -1; 
        int ops = 0;
        for (int i = 0; i < length.size(); i++){
            if (type[i] == 0 && length[i] >= m){
                //cout << "end: " << end << endl;
                if (end < pos[i]){
                    end = pos[i] + m - 1 + k; ops++;
                    //cout << "end: " << end << endl;
                }
                while (end < pos[i+1] - m + 1){
                    end += m - 1 + k; ops++;
                    //cout << "end: " << end << endl;
                }
                
            }
        }

        cout << ops << endl;
        //cout << endl;
    }
    

    return 0;
}