#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long sum = 0, ans = 0;
        set<long long> st = {0};

        for (int i = 0; i < n; i++){
            sum += a[i];

            if (st.count(sum) > 0){
                ans++;
                //sum = 0;
                st.clear();
            }

            st.emplace(sum);
        }
        cout << ans << endl;
    }
    
    return 0;
}