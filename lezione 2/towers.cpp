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
    int num[1001]={};
    while(n--) {
        cin >> a;
        if(num[a]==0) c++;
        num[a]++;
        if(num[a]>m) m++;
    }
    cout << m << " " << c << endl;
}
