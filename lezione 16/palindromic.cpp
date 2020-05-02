/* https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0

We use dynamic programming by defining a matrix a, where a[i][j] is the longest palindromic subsequence between indices i and j.
The recursion is very similar to the one of the longest common subsequence between two strings.
Time and space complexity are O(n^2).
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
	    cin >> s;
	    int l=s.length();
	    int a[l][l];
	    for (int i=l-1; i>=0; i--){
	        for (int j=0; j<l; j++){
	            if (i>j) a[i][j]=0;
	            else if(i==j) a[i][j]=1;
	            else if (s[i]==s[j]) a[i][j]=a[i+1][j-1]+2;
	            else a[i][j]=max(a[i][j-1],a[i+1][j]);
	        }
	    }
	    cout << a[0][l-1] << endl;
	}
}
