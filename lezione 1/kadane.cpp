#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n, sol=0, a, m=-100*1000;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> a;
            sol+=a;
            if(sol>m){m=sol;}
            if(sol<0){sol=0;}
        }
        cout<< m << endl;
        sol=0;
        m=-100*1000;
    }
}
