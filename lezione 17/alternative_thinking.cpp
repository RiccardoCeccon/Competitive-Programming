/* http://codeforces.com/problemset/problem/603/A?locale=en

We count the number of times when the input is different from the previous one and the number of times when it is equal.
The answer is 1+ the former + the maximum between the latter and two. This because if two consecutive inputs are equal we can flip 
the sequence from that input on. If this happens twice we flip the sequence between the two inputs. If it happens more times we can just flip one subsequence.
Time and space complexity are O(n).
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    char a=s[0];
    int ug=0, var=1;
    for (int i=1; i<n; i++){
        if (s[i]==s[i-1] && ug<2) ug++;
        else if(s[i]!=s[i-1]) var++;
    }
    cout << var+ug << endl;
}
