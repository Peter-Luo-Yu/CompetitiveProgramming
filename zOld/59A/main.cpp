#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s; cin >> s;
    
    int upper = 0;
    for (int i = 0; i < s.length(); i++){
        if (isupper(s[i])){
            upper++;
        }
    }
    
    if (upper > s.length()/2){
        string result = "";
        for (int i = 0; i < s.length(); i++){
            result += toupper(s[i]);
        }
        cout << result << endl;

    } else {
        string result = "";
        for (int i = 0; i < s.length(); i++){
            result += tolower(s[i]);
        }
        cout << result << endl;
    }
    
    return 0;
}