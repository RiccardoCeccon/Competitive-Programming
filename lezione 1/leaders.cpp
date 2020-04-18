/* https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

We scan the array backwards to find the right leaders, keeping track of the maximum.
Running time and space complexity are O(n) both.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int64_t t, n;
    cin >> t;
    int64_t m=0;
    vector<int> sol;
    while(t--) {
        cin >> n;
        int64_t A[n];
        for (int i=0; i<n; i++) cin >> A[i];
        for (int i=n-1; i>=0; i--) {
            if (A[i]>=m) {
                m = A[i];
                sol.push_back(m);
            }
        }
        for (int i=sol.size()-1; i>=0; i--) cout << sol[i] << " ";
        cout << endl;
        m=0;
        sol.clear();
    }
}
