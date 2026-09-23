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
    while (t--){
        int n; cin >> n;

        vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];
        sort (arr.begin(), arr.end());

        vector<bool> vis (n);

        int x1 = 2e9, y1 = 2e9, x2 = 2e9, y2 = 2e9;
        for (int i = 0; i < n - 1; i++){
            if (arr[i] == arr[i+1] && vis[i] == false && vis[i+1] == false){
                if (x1 == 2e9){
                    x1 = arr[i];
                    vis[i] = true; vis[i+1] = true;
                    //cout << "set x1: " << arr[i] << endl;
                } 
                else if (y1 == 2e9) {
                    y1 = arr[i];
                    vis[i] = true; vis[i+1] = true;
                    //cout << "set y1: " << arr[i] << endl;
                } else {
                    break;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--){
            if (arr[i] == arr[i-1] && vis[i] == false && vis[i-1] == false){
                if (x2 == 2e9){
                    x2 = arr[i];
                    vis[i] = true; vis[i-1] = true;
                } 
                else if (y2 == 2e9){
                    y2 = arr[i];
                    vis[i] = true; vis[i-1] = true;
                } else {
                    break;
                }
            }
        }

        vector<int> temp = {x1, y1, x2, y2};
        sort (temp.begin(), temp.end());

        //cout << "temp: "; print (temp);

        if (temp[3] == 2e9){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;

            //ll pos1 = (temp[1] - temp[0]) * (temp[3] - temp[2]);
            //ll pos2 = (temp[2] - temp[0]) * (temp[3] - temp[1]);
            //ll pos3 = (temp[3] - temp[0]) * (temp[2] - temp[1]);

            //cout << "poss: " << pos1 << " " << pos2 << " " << pos3 << endl;

            if ((temp[0] == temp[1] || temp[2] == temp[3]) && temp[1] == temp[2]){
                int a;
                if (temp[0] == temp[1]){
                    a = temp[0];
                    cout << a << " " << a << " " << a << " " << a << " " << a << " " << temp[3] << " " << a << " " << temp[3] << endl;
                }
                else {
                    a = temp[3];
                    cout << a << " " << a << " " << a << " " << a << " " << a << " " << temp[0] << " " << a << " " << temp[0] << endl;
                }                
            } 
            else {
                cout << temp[0] << " " << temp[1] << " " << temp[0] << " " << temp[3] << " " << temp[2] << " " << temp[1] << " " << temp[2] << " " << temp[3] << endl;
            }
            
        }
    }
    

    return 0;
}