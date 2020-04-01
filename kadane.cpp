#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n, sol=0, a;
    cin >> T;
    vector<int> A;
    for (int i=0; i<T; i++) {
        cin >> n;
        A.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> a;
            A.push_back(a);
        }
        for (int j=0; j<n; j++) {
            sol+=A[j];
            if(sol<0){sol=0;}
        }
        cout<< sol << endl;
        A.clear();
        sol=0;
    }
}
