/* https://www.spoj.com/problems/PT07X/
We observe that every vertex cover is the complementary of an independent set. Thus the minimum one is the complementay of the LIST.
It wasn't clear to me (since it wasn't written anywhere) that the root was alway zero, and that the edges were given in both "directions".
Running time is O(n) since we scan the tree only once, thanks to Dynamic Programming, which in this case consists in keeping track of the LIST of subtrees.
*/



#include<bits/stdc++.h>
using namespace std;

int64_t LIST(vector<int64_t> adj[], int64_t root, int64_t par, int64_t list[]){
    if (list[root]!=0) return list[root];
    int64_t a=0, b=0;
    for (auto j:adj[root]){
        if (j==par) continue;
        a+=LIST(adj, j, root, list);
        for (auto k:adj[j]){
            if (k==root) continue;
            b+=LIST(adj, k, j, list);
        }
    }
    list[root]=max(a,b+1);
    return list[root];
}

int main(){
    int64_t n, a, b, sol;
    cin >> n;
    vector<int64_t> adj[n];
    for (int i=1; i<n; i++){
       cin >> a >> b;
       adj[a-1].push_back(b-1);
       adj[b-1].push_back(a-1);
    }
    int64_t list[n]={};
    sol=LIST(adj, 0, -1, list);
    cout << n-sol << endl;
}
