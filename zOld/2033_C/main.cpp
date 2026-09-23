#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        
        vector<int> arr (n); set<int> st;
        for (int i = 0; i < n; i++) {cin >> arr[i]; st.insert(arr[i]);}

        int Size = st.size();
        //cout << Size << endl;

        map<int, int> tracker;
        vector<vector<int>> freq (Size, vector<int> (n/2));

        // setting up the storage, remember that it's off by 1
        int idx = 1;
        for (int i = 0; i < n; i++){
            if (tracker[arr[i]] == 0){
                tracker[arr[i]] = idx;
                idx++;
            }
        }

        for (auto x : tracker){
            cout << x.first << " " << x.second << endl;
        } cout << endl;

        if (n % 2 == 0){
            for (int i = n/2; i < n; i++){
                freq[tracker[arr[i]] - 1][i - (n/2)]++;
            }
            for (int i = n/2 - 1; i >= 0; i--){
                freq[tracker[arr[i]] - 1][(n/2) - 1 - i]++;
            }

            int ans = 0;
            cout << "freq -" << endl;
            for (int i = 0; i < freq.size(); i++){
                for (int j = 0; j < freq[i].size(); j++){
                    if ()
                }
                cout << endl;
            }cout << endl;
        }
        


    }
    

    return 0;
}