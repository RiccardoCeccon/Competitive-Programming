#include <bits/stdc++.h>
using namespace std;

DFS_visit(vector<int> adj[], int n, int i, int& t, int color[], int d[], int f[], int p[]){
    t++;
    d[i]=t;
    color[i]=1; //grigio
    for (int j=0; j<n; j++){
        if (adj[i][j]==1 && color[j]=0){
            p[j]=i;
            DFS_visit(adj[], n, j, t, color, d, f, p);
        }
    } 
    color[i]=2; //nero
    t++;
    f[i]=t;
}

int main(){
    int n, m;
    int a, b;
    cin >> n;
    int w[n];
    for (int i=0; i<n; i++) cin >> w[i];
    cin >> m;
    int adj[n][n], adjt[n][n];
    memset(adj, 0, sizeof(int)*n*n);
    memset(adjt, 0, sizeof(int)*n*n);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a-1][b-1]=1;
        adjt[b-1][a-1]=1;
    }
    
    int color[n]={}, d[n]={}, f[n]={}, p[n];
    memset(p, -1, sizeof(int)*n);
    int t=0;
    for (int i=0; i<n; i++){
        if (color[i]==0) DFS_visit(adj[], n, i, t, color, d, f, p);
    }
    
    vector<pair<int,int> >f_ind;
    for (i=0; i<n; i++) {
    f_ind.push_back(make_pair(f[i],i));
    }

    sort(f_ind.begin(),f_ind.end());
    
    int colort[n]={}, dt[n]={}, ft[n]={}, pt[n];
    memset(pt, -1, sizeof(int)*n);
    int t=0;
    for (int i=n-1; i>=0; i--){
        int ind=f_ind[i].second;
        if (colort[ind]==0) DFS_visit(adjt[], n, ind, t, colort, dt, ft, pt);
    }
    
    
}
