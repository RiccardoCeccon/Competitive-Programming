#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n, a;
    cin >> T;
    long sum=0;
    for (int i=0; i<T; i++) {
        cin >> n;
        for (int j=0; j<n-1; j++) {
            cin >> a;
            sum+=a;
        }
        sum=n*(n+1)/2-sum;
        cout<< sum << endl;
        sum=0;
    }
}
