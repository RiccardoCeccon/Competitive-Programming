/* https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0 

To check whether a sequence is the pre-order traversal of some BST, the algorith has the same idea of the Next Larger Element 
problem: at every iteration of the loop we quit the smaller element in the stack, calling "root" the last one. 
The "root" element is the root of the subtree whose right branch the element of the array belongs to.
As whith Next Larger Element problem, running time and space complexity are O(n).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, sol=1;
    cin >> t;
    while(t--){
       cin >> n;
       int a[n];
       for(int i=0; i<n; i++){
           cin >> a[i];
       }
       stack<int> s;
       int root=-1001; //less than minimum number
       for(int i=0; i<n; i++){
           if (a[i]<root) sol=0;
           while (!s.empty() && s.top()<a[i]){
           root=s.top();
           s.pop();
           }
           s.push(a[i]);
       }
       cout << sol << endl;
       sol=1;
    }
}
