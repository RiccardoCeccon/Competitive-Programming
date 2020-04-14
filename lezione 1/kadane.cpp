#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n, sol=0, a, m=-100000;
    cin >> T;
    while(T--){
        cin >> n;
        while(n--) {
            cin >> a;
            sol+=a;
            if(sol>m) m=sol;
            if(sol<0) sol=0;
        }
        cout << m << endl;
        sol=0;
        m=-100*1000;
    }
}
