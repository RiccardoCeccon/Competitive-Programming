/* http://codeforces.com/problemset/problem/277/A?locale=en

We create a bipartite graph between the employees and the languages. If no one knows any language we print n, otherwise we print
the number of connected components of the graph minus one.
Running time and space complexity are O(n+m).
*/



#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m, l, k;
    cin >> n >> m;
    int a[n+m][n+m];
    int no_one=0;
    memset(a, 0, sizeof(int)*(n+m)*(n+m));
    for(int i=0; i<n; i++){
        cin >> l;
        if (l!=0) no_one=1;
        for (int j=0; j<l; j++){
            cin >> k;
            k--;
            a[i][n+k]=1;
            a[n+k][i]=1;
        }
    }
    
    if (no_one==0) {
        cout << n << endl;
        return 0;
    }
    
    int sol=0;
    int visited[n+m]={0}; //0=white, 1=black (gray is not necessary here)
    for (int i=0; i<n; i++){ //BFS for connected components
        if (visited[i]!=0) continue;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int j=Q.front();
            Q.pop();
            if (visited[j]!=0) continue;
            for(int k=0; k<n+m; k++){
                if (a[j][k]==1) Q.push(k);
            }
            visited[j]=1;
        }
        sol++;
    }
    
    cout << sol-1 << endl;
    return 0;
}
