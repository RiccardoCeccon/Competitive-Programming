/* https://codeforces.com/problemset/problem/579/B?locale=en

This problem is solved greedily: we sort all the n^2 (to be precise, n(n-1)/2 ) couples by value, and we greedily form the couples
following this order (if both of the elements are free).
Time complexity is O(n^2*log(n^2))=O(n^2*log(n)) and space complexity is O(n^2).
*/


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
