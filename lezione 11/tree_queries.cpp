#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int root, int b[], int f[], int l[], int& t) {
    b[root] = t;
    l[t]=root;
    t++;
    for (int x: adj[root]) {
        DFS(adj, x, b, f, l, t);
    }
    f[root] = t-1;
}

void add(int a[], int count[], int ind, int& sol){
    count[a[ind]]++;
}

void rem(int a[], int count[], int ind, int& sol){
    sol-=a[ind]*(2*count[a[ind]]-1);
    count[a[ind]]--;
}


int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int c[n];
    for (int i=0; i<n; i++) cin >> c[i];
    
    vector<int> adj[n];
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }
    int b[n], f[n], l[n];
    int t=0;
    DFS(adj, 0, b, f, l, t); 
    
    
    double s=sqrt(n);
    sn=ceil(s);
    vector<tuple<int, int, int, int>> buck[sn+1];
    int v, k, l, r;
    for(int i=0; i<m; i++){
        cin >> v >> k;
        l=b[v]-1;
        r=f[v]-1;
        x=floor(l/s);
        buck[x].push_back(make_tuple(r, l, k, i));
    }
    
    int maxc=*max_element(c,c+n);
    int count[maxc+1];
    int ans[m];
    int sol=0;
    for (int i=0; i<=sn; i++) {
        for(auto b:buck[i]){ 
            r=get<0>(b);
            l=get<1>(b);
            k=get<2>(b);
            
            while (cur_l < l){
                cur_l++;
                rem(a, count, cur_l, sol);
            }
            while (cur_l > l){
                add(a, count, cur_l, sol);
                cur_l--;
            }
            while (cur_r < r){
                cur_r++;
                add(a, count, cur_r, sol);
            }
            while (cur_r > r){
                rem(a, count, cur_l, sol);
                cur_r--;
            }
            
            ans[get<3>(b)]=sol;
        }
    }
    
    for (int i=0; i<m; i++){cout << ans[i] << endl;}
}
