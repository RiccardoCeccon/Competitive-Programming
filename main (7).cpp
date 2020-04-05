
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    int c[n]={0};
    int64_t s[n];
    s[n-1]=a[n-1];
    for (int i=n-2; i>=0; i--){
        s[i]=s[i+1]+a[i];
    }
    int64_t sum = s[0];
    if (sum % 3!=0) {
        cout << 0 << endl; 
        return 0;
    }
    sum = sum/3;
    for (int i=n-1; i>=2; i--){
        if (s[i]==sum) c[i]=1;
    }
    for (int i=n-2; i>=2; i--){
        c[i]+=c[i+1];
    }
    int64_t s2=0;
    int64_t sol=0;
    for (int i=0; i<n-2; i++){
        s2+= a[i];
        if (s2==sum) sol+= c[i+2];
    }
    cout << sol << endl;
}

