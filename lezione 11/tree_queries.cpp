  
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


int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int c[n];
    for (int i=0; i<n; i++) cin >> c[i];
    
    vector<int> adj[n];
    for (int i=0; i<n-1; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }
    int b[n], f[n], list[n];
    int t=0;
    DFS(adj, 0, b, f, list, t); 

    double s=sqrt(n);
    int sn=ceil(s);
    vector<tuple<int, int, int, int>> buck[sn+1];
    int v, k, l, r;
    for(int i=0; i<m; i++){
        cin >> v >> k;
        l=b[v-1];
        r=f[v-1];
        x=floor(l/s);
        buck[x].push_back(make_tuple(r, l, k, i));
    }
    
    for (int i=0; i<=sn; i++) {
        sort(buck[i].begin(),buck[i].end());
    }
    
    int maxc=*max_element(c,c+n);
    int count[maxc+1]={};
    int sumcount[n+1]={};
    int ans[m];
    int cur_l=0; int cur_r=-1, cur_col;
    for (int i=0; i<=sn; i++) {
        for(auto b:buck[i]){ 
            r=get<0>(b);
            l=get<1>(b);
            k=get<2>(b);
            
            while (cur_l < l){
                cur_col=c[list[cur_l]];
                sumcount[count[cur_col]]--;
                count[cur_col]--;
                cur_l++;
            }
            while (cur_l > l){
                cur_l--;
                cur_col=c[list[cur_r]];
                count[cur_col]++;
                sumcount[count[cur_col]]++;
            }
            while (cur_r < r){
                cur_r++;
                cur_col=c[list[cur_r]];
                count[cur_col]++;
                sumcount[count[cur_col]]++;
            }
            while (cur_r > r){
                cur_col=c[list[cur_r]];
                sumcount[count[cur_col]]--;
                count[cur_col]--;
                cur_r--;
            }
            ans[get<3>(b)]=sumcount[k];
        }
    }
    
    for (int i=0; i<m; i++){cout << ans[i] << endl;}
}
