/* https://practice.geeksforgeeks.org/problems/bipartite-graph/1

We perform a BFS over the graph, alternating the side of the bi-partition where to assign each node. 
If at some time two side assignments do not coincide, we return false.
The running time is the same as BFS, i.e. O(E+V).
*/


// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX],int V)
{
    int side[V]={}; //side of bipartite graph (0=unknown, 1/-1 are the sides)
    int color[V]={}; //visit state of BFS
    queue<pair<int,int>> Q;
    for (int i=0; i<V; i++){
        if (color[i]==0) //new connected component
        { 
            Q.push(make_pair(i,1));
            while (!Q.empty()){
                int curside=Q.front().second;
                int ind=Q.front().first;
                Q.pop();
                if (side[ind]==-curside) return false;
                side[ind]=curside;
                if (color[ind]==0) {
                    for (int j=0; j<V; j++) {
                        if (G[ind][j]==1) Q.push(make_pair(j,-curside));
                    }
                    color[ind]=1;
                }
            }
        }
    }
    return true;
}
