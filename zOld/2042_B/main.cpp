#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> arr (n), freq (1000); 
        for (int i = 0; i < n; i++) {cin >> arr[i]; freq[arr[i]-1]++;}

        sort(freq.begin(), freq.end());

        int ones = 0;
        int mores = 0;
        int score = 0;


        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 1) {
                ones++;
            }
            else if (freq[i] > 1) {
                mores++;
            }
        }

        if (ones % 2 == 0) {
            score += (ones / 2) * 2;
        } else {
            score += (ones / 2 + 1) * 2;
        }
        score += mores;

        cout << score << endl;
        
    }
    

    return 0;
}