#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int position(string S, string T){
    int count;

    for (int i = 0; i < S.length(); i++){
        count = 0;
        int index = i;
        for (int j = 0; j < T.length(); j++){
            if (S[index] == T[j]){
                count++;
            }
            index++;
        }
        if (count == T.length()){
            return i;
        }
    }
    return -1;
}

string cut(string S, string T, int pos){
    string temp;
    for (int i = 0; i < pos; i++){
        temp += S[i];
    }
    for (int i = pos + T.length(); i < S.length(); i++){
        temp += S[i];
    }

    return temp;
}


int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string S, T;
    cin >> S >> T;

    while (position(S,T) != -1){
        S = cut(S, T, position(S,T));
    }

    cout << S << endl;
    
}