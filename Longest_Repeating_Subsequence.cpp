/*Longest Repeating Subsequence
Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
Example:
Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.
Input: str = "aabb"
Output: "ab"

Input: str = "aab"
Output: "a"

Input: str = "aabebcdd"
Output: "abd"
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string x, string y){
    int n=x.size();
    int m=y.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=-1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]&&i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
            }
        }
    }
    return dp[n][m];
    // string ans="";
    // int i=n;
    // int j=m;
    // while(i>=1&&j>=1){
    //     if(i==j){
    //         continue;
    //     }
    //     if(x[i-1]==y[j-1]){
    //         if(i==j){
    //             i--;
    //             j--;
    //             continue;
    //         }
    //         ans=ans+x[i-1];
    //         i--;
    //         j--;
    //         continue;
    //     }
    //     else if(dp[i][j-1]>dp[i-1][j]){
    //         j--;
    //         continue;
    //     }
    //     else{
    //         i--;
    //         continue;
    //     }
    // }
    // reverse(ans.begin(),ans.end());
    // return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<lcs(s,s)<<endl;
}