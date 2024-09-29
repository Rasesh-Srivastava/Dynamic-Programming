/*Shortest Common Supersequence
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
Examples:

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke" len=5
https://www.geeksforgeeks.org/shortest-common-supersequence/
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // string a="aggtab";
    // string b="gxtxayb";
    string a,b;
    cin>>a>>b;
    int m=a.size();
    int n=b.size();
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    cout<<dp[m][n];
}
/*Alternate method:
shortestCommonSupersequenceof(a,b)=a.size()+b.size()-LCSlen(a,b)
*/