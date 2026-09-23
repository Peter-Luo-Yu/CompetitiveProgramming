#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<string> zodiac = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map<string, int> data;

    vector<vector<string>> info;


    for (int i = 0; i < n; i++){
        string a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;

        info.push_back({a,b,c,d,e,f,g,h});
    }

    /*
    for (int i = 0; i < info.size(); i++){
        for (int j = 0; j < info[i].size(); j++){
            cout << info[i][j] << " ";
        }
        cout << endl;
    } */

    data["Bessie"] = 1200000;

    while (!(data.count("Bessie") == 1 && data.count("Elsie") == 1)){

        for (int j = 0; j < info.size(); j++) {
            if (data.count(info[j][7]) == 0){
                continue;
            }
            
            if (info[j][3] == "previous"){
                int initial_year = data[info[j][7]] % 12;       // bessie year
                int final_year;                              // new cow's year

                for (int z = 0; z < 12; z++){
                    if (zodiac[z] == info[j][4]){
                        final_year = z;
                    }
                }

                int diff;

                if (initial_year > final_year){
                    diff = initial_year - final_year;
                } else {
                    diff = 12 - (final_year - initial_year);
                }
                
                //cout << "cow: " << info[j][0] << " diff: " << initial_year << " " << final_year << " " << diff;

                data[info[j][0]] = data[info[j][7]] - diff;

                //cout << " final: " << data[info[j][0]] << endl;

            } else {
                int initial_year = data[info[j][7]] % 12;       // bessie year
                int final_year;                              // new cow's year

                for (int z = 0; z < 12; z++){
                    if (zodiac[z] == info[j][4]){
                        final_year = z;
                    }
                }

                int diff;

                if (initial_year < final_year){
                    diff = final_year - initial_year;
                } else {
                    diff = 12 - (initial_year - final_year);
                }
                
                //cout << "cow: " << info[j][0] << " diff: " << initial_year << " " << final_year << " " << diff;

                data[info[j][0]] = data[info[j][7]] + diff;

                //cout << " final: " << data[info[j][0]] << endl;

            }

        }
    } 

    cout << abs(data["Bessie"] - data["Elsie"]) << endl;

    /*
    for (auto x : data){
        cout << x.first << " " << x.second << endl;
    }*/
    
    return 0;
}