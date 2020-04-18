/* https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

We xompute the prefix and suffix maximums, and at every index we sum to the solution the minimum between the max from the left 
and the max from the right, and the value of the array in that position.
Time and space complexity are O(n).
*/

#include <iostream>
using namespace std;

int main() {
    int t, n, m=0, s=0;
    cin >> t;
    while(t--) {
        cin >> n;
        int A[n], maxl[n];
        for (int i=0; i<n; i++) {
            cin >> A[i];
            if(A[i]>m) m=A[i];
            maxl[i]=m;
        }
        m=0;
        for (int i=n-1; i>=0; i--) {
            if(A[i]>m){m=A[i];}
            s+=min(maxl[i],m)-A[i];
        }
        cout << s << endl;
        m=0;
        s=0;
    }
}
