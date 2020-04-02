#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, n, a;
    cin >> T;
    vector<int> S;
    vector<pair<int,int>> F;
    int fin;
    for (int i=0; i<T; i++) {
        cin >> n;
        S.reserve(n);
        F.reserve(n);
        for (int j=0; j<n; j++) cin >> S[j];
        for (int j=0; j<n; j++) {
            cin >> a;
            F.push_back(make_pair(k,i))
        }
        sort (F.begin(),F.end());
        fin=0;
        for (int j=0; j<n; j++) {
            if (S[ind[j]]>=fin) {cout>> ind[j]+1>> " ";
            fin=F[ind[j]];
            }
        S.clear();
        F.clear();
        ind.clear();
        cout>> endl;
    }
}
