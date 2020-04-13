// http://codeforces.com/problemset/problem/353/B?locale=en

/* This algorithm solves the Two Heaps problem. 
If a number appers only once in the array, we give it to the smallest heap.
If a number appears twice or more we give it to both heaps (it doesn't matter how it is distributed because once the heap has 
the number, the result doesn't change depending on how many times one number appears in the heap).
n1 and n2 represent the number of DISTINCT numbers in the first and the second heap. 
Test number 6 is wrong because it wants the two heaps to have the same number of elements, but what matter is the number of distinct elements in the heaps, which is actually the same.
Indeed, the number of distinct pairs is correct.
It runs in O(n) time because we have to read the array only once and then we work with the array count which has constant size=90.
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n*=2;
    int a[n], count[90]={0}; 
    for (int i=0; i<n; i++) {
        cin >> a[i];
        count[a[i]-10]++;
    }
    int n1=0, n2=0;
    for (int i=0; i<90; i++){
        if (count[i]==1 && n1<=n2) {
            n1++;
            count[i]=-1;
        }
        else if (count[i]==1 && n2<n1) {
            n2++;
            count[i]=-2;
        }
        else if (count[i]>=2) {
            n1++; n2++;
        }
    }
    cout << n1*n2 << endl;
    for (int i=0; i<n; i++) {
        if (count[a[i]-10]==-1) cout << 1 << " ";
        else if (count[a[i]-10]==-2) cout << 2 << " ";
        else {
            cout << count[a[i]-10]%2 + 1 << " ";
            count[a[i]-10]--;
        }
    } 
}
