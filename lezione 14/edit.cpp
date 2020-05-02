/* https://practice.geeksforgeeks.org/problems/edit-distance/0

We use dynamic programming to define the matrix a, where a[i][j] stands for the edit distance between the first word up to the i-th letter
and the second word up to the j-th letter. the recursion is simple: if s1[i]=s2[j], then we don't have additional edits: a[i][j]=a[i-1][j-1],
otherwise a[i][j]=max( a[i-1][j], a[i][j-1], a[i-1][j-1]).
Running time and space complexity are O(l1*l2).
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, l1, l2;
    string s1, s2;
    cin >> t;
    while (t--){
        cin >> l1 >> l2 >> s1 >> s2;
        int a[l1+1][l2+1];
        for (int i=0; i<=l1; i++){
            for (int j=0; j<=l2; j++){
                if (i==0) a[i][j]=j;
                else if (j==0) a[i][j]=i;
                else if (s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1];
                else a[i][j]=1+min(min(a[i-1][j-1], a[i][j-1]), a[i-1][j]);
            }
        }
        cout << a[l1][l2] << endl;
    }
    return 0;
}

