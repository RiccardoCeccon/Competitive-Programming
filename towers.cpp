/*
This algorithm solves the Towers Problem.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, a, c=0, m=0;
    cin >> n;
    vector<int> num;
    num.reserve(1000);
    for (int i=0; i<n; i++) {
        cin >> a;
        if(num[a-1]==0){c++;}
        num[a-1]++;
        if(num[a-1]>m){m++;}
    }
    cout << m << " " << c << endl;
}
