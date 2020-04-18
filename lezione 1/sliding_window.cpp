/* https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

As taught at lesson, we use a deque: we first eliminate the elements that are too far away from i, then the elements on the front 
that are <= A[i] and then we take the front as the sliding maximum. 
Running time is O(n) because we scan the array only once and elements are put and popped from the deque only once at most.
Space complexity is O(n).
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int t, n, K, a;
    cin >> t;
    deque <int> d; 
    while(t--) {
        cin >> n >> K;
        int A[n], sol[n];
        for (int i=0; i<n; i++) cin >> A[i];
        for (int i=0; i<n; i++) {
            while(!(d.empty()) && d.front()<=i-K){d.pop_front();}
            while(!(d.empty()) && A[d.back()]<=A[i]){d.pop_back();}
            d.push_back(i);
            sol[i]=A[d.front()];
        }
        for (int i=K-1; i<n; i++) cout << sol[i] << " ";
        cout << endl;
        d.clear();
    }
}
