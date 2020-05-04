/* http://codeforces.com/problemset/problem/427/C?locale=en

We compute the SCCs doing firstly a DFS in the graph and then a DFS in the transposed graph, following the finish order of the first DFS.
For every SCC we compute the minimum weight and the number of times it is reached. 
Running time and space complexities are O(n+m).
*/


#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void DFS_visit(vector<int> adj[], int i, int color[], stack<int>& f){
    color[i]=1; //grigio
    for (auto j:adj[i]){
        if (color[j]==0){
            DFS_visit(adj, j, color, f);
        }
    } 
    color[i]=2; //nero
    f.push(i);
}

void DFS_visit_t(vector<int> adj[], int i, int color[], vector<int>&ind, int w[]){
    ind.push_back(w[i]);
    color[i]=1; //grigio
    for (auto j:adj[i]){
        if (color[j]==0){
            DFS_visit_t(adj, j, color, ind, w);
        }
    } 
    color[i]=2; //nero
    }

int main(){
    int n, m;
    int a, b;
    int64_t sol=0, ways=1;
    cin >> n;
    int w[n];
    for (int i=0; i<n; i++) cin >> w[i];
    cin >> m;
    vector<int> adj[n], adjt[n];
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adjt[b-1].push_back(a-1);
    }
    
    int color[n]={};
    stack<int> f;
    for (int i=0; i<n; i++){
        if (color[i]==0) DFS_visit(adj, i, color, f);
    }
    
    //for (int i=0; i<n; i++){
    //    cout << d[i] <<" "<< p[i]<<" " << f[i]<< endl;
    //}
    
    
    //vector<pair<int,int> >f_ind;
    //for (int i=0; i<n; i++) {
    //f_ind.push_back(make_pair(f[i],i));
    //}

    //sort(f_ind.begin(),f_ind.end());
    
    //for (auto i:f_ind) cout << i.first << " " << i.second<< endl;
    
    int colort[n]={};
    int min_vec, ways_vec=0;
    while( !f.empty() ){
        int ind=f.top();
        f.pop();
        vector<int> w_scc;
        if (colort[ind]==0) {
            DFS_visit_t(adjt, ind, colort, w_scc, w);
            //for (auto j:w_scc) cout<< j << " ";
            //cout << endl;
            
            min_vec = *min_element(w_scc.begin(), w_scc.end());
            for (auto j:w_scc) if (j==min_vec) ways_vec++;
            sol += min_vec;
            ways = (ways*ways_vec) % MOD;
            w_scc.clear();
            ways_vec=0;
        }
    }
    
    cout << sol << " " << ways << endl;
}
