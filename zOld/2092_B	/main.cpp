#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void print (vector<int> list){
    for (int x : list) {cout << x << " ";} cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        string a,b; cin >> a >> b;

        vector<int> top, bot;   // top diagonal, bot diagonal

        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                top.push_back(a[i] - '0');
            } else {
                top.push_back(b[i] - '0');
            }
        }
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                bot.push_back(b[i] - '0');
            } else {
                bot.push_back(a[i] - '0');
            }
        }

        //print(top); print(bot); 

        int top_ones = 0, top_zeros = 0, bot_ones = 0, bot_zeros = 0;

        //process the top first
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                if (top[i] == 1){
                    top_ones++;
                }
            } else {
                if (top[i] == 0){
                    top_zeros++;
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                if (bot[i] == 0){
                    bot_zeros++;
                }
            } else {
                if (bot[i] == 1){
                    bot_ones++;
                }
            }
        }

        //cout << top_ones << " " << top_zeros  << endl;
        //cout << bot_ones << " " << bot_zeros  << endl;
        //cout << endl;

        if (top_ones > top_zeros || bot_ones > bot_zeros){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }


    }


    
    
    return 0;
}