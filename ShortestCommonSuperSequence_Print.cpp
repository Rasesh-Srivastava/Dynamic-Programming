/*Shortest Common Supersequence
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
Examples:

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke" len=5
https://www.geeksforgeeks.org/shortest-common-supersequence/
this problem deals with outputting the string
*/
#include <bits/stdc++.h>
using namespace std;
string shortestCommonSupersequence(string x, string y){
    int n=x.size();
    int m=y.size();
    int dp[n+1][m+1];
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         if(i==0){
    //             dp[i][j]=j;
    //         }
    //         else if(j==0){
    //             dp[i][j]==i;
    //         }
    //     }
    // }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // Below steps follow recurrence relation
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans="";
    int i=n;
    int j=m;
    while(i>0&&j>0){
        // if(i!=0&&j==0){
        //     for(int k=i;k>=1;k--)
        //     ans=ans+x[k-1];
        //     break;
        // }
        // if(i==0&&j!=0){
        //     for(int k=j;k>=1;k--)
        //     ans=ans+y[k-1];
        //     break;
        // }
        

        if(x[i-1]==y[j-1]){
            ans=ans+x[i-1];
            i--;
            j--;
            continue;
        }
        // else if(dp[i][j-1]>dp[i-1][j]){
        //     ans=ans+y[j-1];
        //     j--;
        //     continue;
        // }
        // // else if(dp[i][j-1]==dp[i-1][j]){
        // //     ans=ans+x[i-1]+y[j-1];
        // //     i--;
        // //     j--;
        // //     continue;
        // // }
        else if(dp[i][j-1]<dp[i-1][j]){
            ans=ans+y[j-1];
            j--;
            continue;
        }
        else{
            ans=ans+x[i-1];
            i--;
        }
    }
    while(i>0){
        ans=ans+x[i-1];
        i--;
    }
    while(j>0){
        ans=ans+y[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<shortestCommonSupersequence(a,b)<<endl;
    
}
