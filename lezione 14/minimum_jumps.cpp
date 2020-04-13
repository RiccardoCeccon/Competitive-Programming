#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> n;
        int A[n], c[n];
        for (int j=0; j<n; j++) cin >> c[j];
        A[n-1]=0;
        for (int j=n-2; j>=0; j--){
            if (c[j]==0) A[j] = n+1;
            else A[j] = 1 + *min_element(A+j, A+j+c[j]);
        }
        for (int j=0; j<n; j++) {
            if (A[j]>=n) A[j] = -1;
        }
        cout << A[0] << endl;
    }
}
 
