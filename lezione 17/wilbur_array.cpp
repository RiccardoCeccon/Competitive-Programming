/* http://codeforces.com/problemset/problem/596/B?locale=en

The answer is b_0+sum_{i=1}^n |b_i-b_{i-1}|, because scanning the array from the left we update the queue of the array from 
b_i on, making it equal to b_i. To get b_{i+1} so we have to perform |b_{i+1}-b_i|. This has to be performed at every step.
Running time is O(n), space complexity is O(1).
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, b, prev;
    cin >> n;
    cin >> s;
    prev=s;
    for (int i=1; i<n; i++) {cin >> b;
        s += b-prev;
        prev = b;
    }
    cout << s << endl;
}
