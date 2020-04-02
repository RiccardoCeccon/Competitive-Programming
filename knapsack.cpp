/*
This algorithm solves the 0-1 knapsack problem.
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
    
    int A[S+1][n+1];
    
    for (int i=0; i<=n; i++) {A[0][i]=0;}
    for (int j=1; j<=S; j++) {A[j][0]=0;}
    for (int i=1; i<=n; i++){
        for (int j=1; j<=S; j++){
            if (weight[i-1]<=j) A[j][i]= max(A[j][i-1], A[j-weight[i-1]][i-1] + value[i-1]);
            else A[j][i]= A[j][i-1];
        }
    }
    cout << A[S+1][n+1];
}
