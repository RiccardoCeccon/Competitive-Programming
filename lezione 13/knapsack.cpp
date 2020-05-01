/* https://www.spoj.com/problems/KNAPSACK/

We use dynamic programming to solve the 0-1 Knapsack problem. We define the matrix A where A[i][j] is the maximum value you can get with a capacity of j,
using only the first i elements. 
Running time is O(n*S), and also space complexity.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int S, n;
    cin >> S;
    cin >> n;
    int weight[n], value[n];
    for (int i=0; i<n; i++) {
        cin >> weight[i] >> value[i];
    }
    
    int A[n+1][S+1];
    
    for (int i=0; i<=n; i++) {A[i][0]=0;}
    for (int j=1; j<=S; j++) {A[0][j]=0;}
    for (int i=1; i<=n; i++){
        for (int j=1; j<=S; j++){
            if (weight[i-1]<=j) A[i][j]= max(A[i-1][j], A[i-1][j-weight[i-1]] + value[i-1]);
            else A[i][j]= A[i-1][j];
        }
    }
    cout << A[n][S];
}
