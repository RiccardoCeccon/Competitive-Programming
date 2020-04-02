// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

/*
This algorithm solves the Trapping Rain Water Problem.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n, a, m=0, s=0;
    cin >> T;
    vector<int> A, maxr, maxl;
    for (int i=0; i<T; i++) {
        cin >> n;
        A.reserve(n);
        maxr.reserve(n);
        maxl.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> a;
            A.push_back(a);
            if(a>m){m=a;}
            maxl[j]=m;
        }
        m=0;
        for (int j=n-1;j>=0;j--) {
            if(A[j]>m){m=A[j];}
            s+=min(maxl[j],m)-A[j];
        }
        cout << s << endl;
        m=0;
        A.clear();
        maxr.clear();
        maxl.clear();
        s=0;
    }
}
