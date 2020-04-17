/* https://practice.geeksforgeeks.org/problems/largest-even-number/0

We want to put higher digits in higher position, with the exception that the last one should be even, if possible. We scan a counter
so that first we pick an even digit and then all the other ones in ascending order.
Running time and space complexity are both O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, l, r;
    string str;
    cin >> t;
    while(t--){
        int dig[10]={};
        cin >> str;
        l=str.length();
        int sol[l];
        for (int i=0; i<l; i++) {
            r=str[i]-'0';
            dig[r]++;
        }
        int count=0;
        for (int i=0; i<10; i+=2){
           if(dig[i]!=0) {
               dig[i]--;
               sol[0]=i;
               count++;
               break;
           }
       }
       for (int i=0; i<10; i++){
           for (int k=0; k<dig[i]; k++) sol[count++]=i;
       }
       for (int i=l-1; i>=0; i--) cout << sol[i];
       cout << endl;
    }
}
