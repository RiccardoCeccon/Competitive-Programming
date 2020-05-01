#include<bits/stdc++.h>
using namespace std;

int find(int64_t t, int64_t p[]) {
  if (t == p[t]) return t;
  p[t] = find(p[t], p);
  return p[t];
}

void union_ds(int64_t a, int64_t b, int64_t p[], int64_t rank[]) {
  a = find(a, p);
  b = find(b, p);
  if (rank[a] > rank[b]) {
    p[b] = a;
    rank[a] += rank[b];
  } else {
    p[a] = b;
    rank[b] += rank[a];
  }
}

int main(){
    int64_t n, m;
    int64_t a,b,c;
    cin >> n >> m;
    tuple<int64_t,int64_t,int64_t> e[m];
    int64_t sol=0;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        e[i]=make_tuple(c,a-1,b-1);
    }
    sort(e,e+m);
    
    int64_t rank[n]={};
    memset(rank,1,n);
    int64_t p[n];
    for (int64_t i=0; i<n; i++) p[i]=i;
    
    for (int i=0; i<m; i++){
        a=get<1>(e[i]);
        b=get<2>(e[i]);
        c=get<0>(e[i]);
        if ( find(a,p) != find(b,p) ) {
            union_ds(a,b,p,rank);
            sol+=c;
        }
    }
    cout << sol << endl;
}
