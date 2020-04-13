// https://practice.geeksforgeeks.org/problems/next-larger-element/0

/*
This algorithm solves the Next Larger Element problem.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

int main() {
    int T, n, a;
    cin >> T;
    vector<int> A, sol;
    stack<int> s; 
    for (int i=0; i<T; i++) {
        cin >> n;
        A.reserve(n);
        sol.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> a;
            A.push_back(a);
        }
        for (int j=n-1;j>=0;j--) {
            while(!s.empty() && A[j]>=s.top()){s.pop();}
            if(s.empty()){sol.push_back(-1);}
            else{sol.push_back(s.top());}
            s.push(A[j]);
        }
        for (int j=n-1;j>=0;j--) {
            cout << sol[j] << " ";
        }
        cout << endl;
        A.clear();
        sol.clear();
        while (!s.empty()){s.pop();}
    }
}
