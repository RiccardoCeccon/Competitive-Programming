// https://practice.geeksforgeeks.org/problems/largest-even-number/0

#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, l, r;
    string N;
    cin >> T;
    for (int i=0; i<T; i++){
        int dig[10]={0};
        cin >> N;
        l=N.length();
        int sol[l];
        for (int j=0; j<l; j++) {
            r=N[j]-'0';
            dig[r]++;
        }
        int count=0;
        for (int j=0; j<10; j+=2){
           if(dig[j]!=0) {
               dig[j]--;
               sol[0]=j;
               count++;
               break;
           }
       }
       for (int j=0; j<10; j++){
           for (int k=0; k<dig[j]; k++){
               sol[count++]=j;
           }
       }
       for (int j=l-1; j>=0; j--){
           cout << sol[j];
       }
       cout << endl;
    }
}
