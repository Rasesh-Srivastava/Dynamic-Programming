/*
Longest Palindromic Subsequence
Given a sequence, find the length of the longest palindromic subsequence in it.
Example :
Input:"bbbab"
Output:4
concept: ans=lcs(a,reverse(a)) ;)
*/
#include <bits/stdc++.h>
using namespace std;
string lcs(string x, string y){
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
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
            }
        }
    }
    string ans="";
    int i=n;
    int j=m;
    while(i>=1&&j>=1){
        if(x[i-1]==y[j-1]){
            ans=ans+x[i-1];
            i--;
            j--;
            continue;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
            continue;
        }
        else{
            i--;
            continue;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string a;
    cin>>a;
    string s1=a;
    reverse(a.begin(),a.end());
    string s2=a;
    cout<<lcs(s1,s2)<<endl;
    return 0;
}