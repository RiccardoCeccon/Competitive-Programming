/* https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
The sum of all numbers from 1 to n is n(n+1)/2, so that if we subtract from this the sum of the array, we get the missing number.
Time complezity is O(n), space complexity is O(1).
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int64_t t, n, a;
    cin >> t;
    int64_t sum=0;
    while(t--) {
        cin >> n;
        for (int i=0; i<n-1; i++) {
            cin >> a;
            sum += a;
        }
        sum=n*(n+1)/2-sum;
        cout<< sum << endl;
        sum=0;
    }
}
