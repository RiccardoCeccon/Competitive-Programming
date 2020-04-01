// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

/*
This algorithm finds and prints from left to right all the leaders of an array. An element of an array is a right leader if
it is greater or equal to all the elements to its right.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    vector<int> A,sol;
    int a,m=0;
    for (int i=0; i<T; i++) {
        cin >> n;
        A.reserve(n);
        sol.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> a;
            A.push_back(a);
        }
        for (int j=n-1;j>=0;j--) {
            if (A[j]>=m) {
                m = A[j];
                sol.insert(sol.begin(), m); 
            }
        }
        for (int j=0;j<sol.size();j++) {
            cout << sol[j] << " ";
        }
        cout << endl;
        m=0;
        A.clear();
        sol.clear();
    }
}
