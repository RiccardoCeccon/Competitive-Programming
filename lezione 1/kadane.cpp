/* https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

We run a prefix sum and we put it to zero every time it becomes negative. We keep track of the maximum of the prefix sum.
Running time is O(n) and space complexity is O(1). 
*/

#include <iostream>
using namespace std;

int main() {
    int t, n, sol=0, a, m=-100000;
    cin >> t;
    while(t--){
        cin >> n;
        while(n--) {
            cin >> a;
            sol+=a;
            if(sol>m) m=sol;
            if(sol<0) sol=0;
        }
        cout << m << endl;
        sol=0;
        m=-100000;
    }
}
