#include <bits/stdc++.h>
using namespace std;

int magic(int n){
    if(n==0) return 1;
    else if (n%10==1) return magic(n/10);
    else if (n%100==14) return magic(n/100);
    else if (n%1000==144) return magic(n/1000);
    else return 0;
}

int main() {
    int n;
    cin >> n;
    if (magic(n)==1) cout << "YES";
    else cout << "NO";
}
