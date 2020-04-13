
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    char a=s[0];
    int ug=0, var=1;
    for (int i=1; i<n; i++){
        if (s[i]==s[i-1] && ug<2) ug++;
        else if(s[i]!=s[i-1]) var++;
    }
    cout << var+ug << endl;
}
