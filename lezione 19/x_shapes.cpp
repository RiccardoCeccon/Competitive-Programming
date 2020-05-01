/* https://practice.geeksforgeeks.org/problems/x-total-shapes/0

We build a graph where we connect two 'X' entries of the matrix if they are adjacent.
Then we run BFS in order to find the number of connected components. 
Space complexity and running time are O(n*m).
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    char x;
    cin >> t;
    while (t--){
        cin >> n >> m;
        vector<int> v[n*m]; 
        int a[n][m]={};
        for( int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> x;
                if (x =='X') a[i][j]=1;
            }
        }
        
        for( int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (a[i][j]==1){ // (i,j) <-> n*j+i
                    if (i!=0 && a[i-1][j]==1) v[n*j+i].push_back(n*j+i-1);
                    if (j!=0 && a[i][j-1]==1) v[n*j+i].push_back(n*(j-1)+i);
                    if (i!=n-1 && a[i+1][j]==1) v[n*j+i].push_back(n*j+i+1);
                    if (j!=m-1 && a[i][j+1]==1) v[n*j+i].push_back(n*(j+1)+i);
                }
            }
        }
        
        
        int sol=0;
        int visited[n*m]={}; //0=white, 1=black (gray is not necessary here)
        for (int i=0; i<n*m; i++){ //BFS for connected components
            if (visited[i]!=0) continue;
            if (a[i%n][i/n]==0) continue;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int j=Q.front();
                Q.pop();
                if (visited[j]!=0) continue;
                for(auto k : v[j]){
                    Q.push(k);
                }
                visited[j]=1;
            }
            sol++;
        }
        cout << sol << endl;
    }
}
