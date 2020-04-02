// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

/*
This algorithm solves the Sliding Window maximum problem.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

int main() {
    int T, n, K, a;
    cin >> T;
    vector<int> A, sol;
    deque <int> d; 
    for (int i=0; i<T; i++) {
        cin >> n;
        cin >> K;
        A.reserve(n);
        sol.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> a;
            A.push_back(a);
        }
        for (int j=0; j<n; j++) {
            while(!(d.empty()) && d.front()<=j-K){d.pop_front();}
            while(!(d.empty()) && A[d.back()]<=A[j]){d.pop_back();}
            d.push_back(j);
            sol.push_back(A[d.front()]);
        }
        for (int j=K-1; j < n; j++) {
            cout << sol[j] << " ";
        }
        cout << endl;
        A.clear();
        sol.clear();
        d.clear();
    }
}
