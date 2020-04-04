
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    long s = accumulate(a, a+n, 0);
    long s1=0, s2=0;
    int i=0, j=n-1;
    
    while (s1+a[i]<=s/2){
        s1=s1+a[i++];
    }
    
    while (s2+a[j]<=s/2){
        s2=s2+a[j--];
    }
    
    if(i==j) {
        if(s1<=s2) i=i+1;
        else j=j-1;
    }
    j=n-1-j;
    cout << i << " " << j << endl;
}
