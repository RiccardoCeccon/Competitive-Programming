#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, i, j;
    cin >> n;
    n*=2;
    vector<tuple<int, int, int>> v;
    for (int i=2; i<=n; i++){
        for (int j=1; j<i; j++){
            cin >> a;
            v.push_back(make_tuple(a, i, j));
        }
    }
    sort(v.begin(),v.end());
    int sol[n]={0};
    for (int k=v.size(); k>=0; k--){
        i=get<1>(v[k]);
        j=get<2>(v[k]);
        if(sol[i-1]==0 && sol[j-1]==0) {
            sol[i-1]=j;
            sol[j-1]=i;
        }
    }
    for (int i=0; i<n; i++) cout << sol[i] << " ";
    cout << endl;
}
