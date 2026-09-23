#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;

    while (t--){
        int n, x; cin >> n >> x;

        vector<ll> students (n);

        for (int i = 0; i < n; i++) {cin >> students[i];}
        sort (students.begin(), students.end());

        int count = 0; 
        
        ll Min = 10000000000;
        int team_size = 0;
        for (int i = students.size() - 1; i >= 0; i--){
            if (students[i] >= x){
                count++;
            }
            else {
                team_size++;
                Min = min (Min, students[i]);

                if (Min * team_size >= x){
                    count++;
                    team_size = 0;
                    Min = 10000000000;
                } 
            }
        }

        cout << count << endl;
    }

    return 0;
}