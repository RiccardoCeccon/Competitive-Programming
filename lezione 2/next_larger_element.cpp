/* https://practice.geeksforgeeks.org/problems/next-larger-element/0

This algorithm solves the Next Larger Element problem. With a similar approach to Sliding Window, we create a stack where 
at every step we pop elements until a larger one is found.
Time and space complexity are O(n) because we scan the array only once, and every element of the stack is eliminated 
at most once.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    stack<int64_t> s; 
    while(t--) {
        cin >> n;
        int64_t A[n];
        int64_t sol[n];
        for (int i=0; i<n; i++) cin >> A[i];
        for (int i=n-1;i>=0;i--) {
            while ( !s.empty() && A[i]>=s.top() ) s.pop();
            if(s.empty()) sol[i]=-1;
            else sol[i] = s.top();
            s.push(A[i]);
        }
        for (int i=0; i<n; i++) cout << sol[i] << " ";
        cout << endl;
        while (!s.empty()) s.pop();
    }
}
