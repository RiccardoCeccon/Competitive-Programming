#include<bits/stdc++.h>
using namespace std;

int64_t LIST(vector<int64_t> adj[], int64_t root, int64_t list[]){
    if (list[root]!=0) return list[root];
    if (adj[root].empty()) return 1;
    int64_t a=0, b=0;
    for (auto j:adj[root]){
        a+=LIST(adj, j, list);
        for (auto k:adj[j]){
            b+=LIST(adj, k, list);
        }
    }
    list[root]=max(a,b+1);
    return list[root];
}

int main(){
    int64_t n, a, b, sol;
    cin >> n;
    vector<int64_t> adj[n];
    int64_t sum=0;
    for (int i=1; i<n; i++){
       cin >> a >> b;
       sum+=b;
       adj[a-1].push_back(b-1);
    }
    int64_t root=n*(n+1)/2-sum-1; //missing number
    int64_t list[n]={0};
    sol=LIST(adj, root, list);
    cout << n-sol << endl;
}