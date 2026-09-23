#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

set<int> poss;

void print (int d, vector<int> a, vector<int> b){
    cout << "DAY: " << d << "\n";
    cout << "A: ";
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "B: ";
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
}

void search (int day, int a, int b, vector<int> a_buckets, vector<int> b_buckets){
    if (day == 4){
        poss.insert(a);
        return;
    }

    for (int i = 0; i < a_buckets.size(); i++){
        int bucket = a_buckets[i];

        vector<int> new_b = b_buckets;
        vector<int> new_a = a_buckets; 

        new_b.push_back(new_a[i]);
        new_a.erase(new_a.begin() + i);

        //print(day, a_buckets, b_buckets);

        search(day + 1, b+bucket, a-bucket, new_b, new_a);  // must use ++day, pre increment
    }
}


int main() {

    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> a_buckets (10), b_buckets(10);
    for (int i = 0; i < 10; i++){
        cin >> a_buckets[i];
    }
    for (int i = 0; i < 10; i++){
        cin >> b_buckets[i];
    }

    search(0, 1000,1000, a_buckets, b_buckets);
    cout  << poss.size() << endl;


    /*
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
    */


    return 0;
}