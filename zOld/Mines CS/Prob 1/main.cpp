#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin>>n;
    pair<long double, int> slopes[2*n];
    for (int i=0;i<n;i++) {
        long double a,b,c; cin>>a>>b>>c;
        slopes[2*i] = make_pair(b/a,1);
        slopes[2*i+1] = make_pair(c/a,2);
    }

    for (int i=0;i<2*n;i++) {
        cout << slopes[i].first << " " << slopes[i].second << endl;
    }
    cout << "--------------------------" << endl;
    sort(slopes, slopes+2*n);
    for (int i=0;i<2*n;i++) {
        cout << slopes[i].first << " " << slopes[i].second << endl;
    }
    int cnt=0, ans=0;
    for (int i=0;i<2*n;i++) {
        if (slopes[i].second == 1) {
            cnt ++;
        }
        else {
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}