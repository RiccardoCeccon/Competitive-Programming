/* https://practice.geeksforgeeks.org/problems/firing-employees/0

We store in adjacency list the edges of the graph and through a DFS we compute the degree of every node.
Then, as required, we compute the sum of the degree and of the rank of the node, checking wheter it is a prime number.
Running time and space complexity are O(n) because the list of the edges has just n-1 elements and we scan the tree only once 
per node to make the BFS.
*/
#include <bits/stdc++.h>
using namespace std;


bool isprime(int n){
    if (n==1) return false;
    if (n==2 || n==3 || n==5) return true;
    if (n%2==0) return false;
    for (int i=3; i<=sqrt(n); i+=2){
        if (n%i==0) return false;
    }
    return true;
}


int main(){
    int t, n, a;
    cin >> t;
    while(t--){
        cin >> n;
        int sol=0;
        vector<int> subord[n];
        queue<int> Q;
        for (int i=0; i<n; i++){
            cin >> a;
            if (a==0) Q.push(i); //boss
            else subord[--a].push_back(i);
        }
        //BFS for degree
        int degree[n]={};
        while(!Q.empty()){
            int emp=Q.front();
            Q.pop();
            for (auto j:subord[emp]){
                Q.push(j);
                degree[j]=degree[emp]+1;
            }
        }
        for (int i=0; i<n; i++){
            if(isprime(degree[i]+i+1) && degree[i]!=0) sol++;
        }
        cout << sol << endl;
    }
    return 0;
}
