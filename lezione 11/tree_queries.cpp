/* https://codeforces.com/contest/375/problem/D

We perform Mo's algorithm applied to pre-order DFS read of the tree and translation of the input v into a pair of indices. 
We then check if between these two indices there are numbers in quantity >=k.
The add and rem functions consist just in an update of counters.
Running time is O((n+m)*sqrt(n)+m*log(m)), space complexity is O(n+m).
*/



#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int root, int par, int b[], int f[], int l[], int& t) {
    b[root] = t;
    l[t]=root;
    t++;
    for (int x: adj[root]) {
        if (x==par) continue;
        DFS(adj, x, root, b, f, l, t);
    }
    f[root] = t-1;
}

void add(int ind, int count[], int sumcount[], int c[], int list[]){
    int cur_col=c[list[ind]];
    count[cur_col]++;
    sumcount[count[cur_col]]++;
}

void rem(int ind, int count[], int sumcount[], int c[], int list[]){
    int cur_col=c[list[ind]];
    sumcount[count[cur_col]]--;
    count[cur_col]--;
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
        adj[y].push_back(x);
    }
    int b[n], f[n], list[n];
    int t=0;
    DFS(adj, 0, -2, b, f, list, t); 

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
    
    for (int i=0; i<=sn; i++){
        sort(buck[i].begin(), buck[i].end());
    }
    
    int maxc=*max_element(c,c+n);
    int count[maxc+1]={};
    int sumcount[n+1]={};
    int ans[m];
    int cur_l=0; int cur_r=-1, cur_col;
    
    for(int i=0; i<=sn; i++){
        for(auto b:buck[i]){ 
            r=get<0>(b);
            l=get<1>(b);
            k=min(get<2>(b),n);
            
            while (cur_l < l){
                rem(cur_l++, count, sumcount, c, list);
            }
            while (cur_l > l){
                add(--cur_l, count, sumcount, c, list);
            }
            while (cur_r < r){
                add(++cur_r, count, sumcount, c, list);
            }
            while (cur_r > r){
                rem(cur_r--, count, sumcount, c, list);
            }
            ans[get<3>(b)]=sumcount[k];
        }
    }
    
    for (int i=0; i<m; i++){cout << ans[i] << endl;}
}
