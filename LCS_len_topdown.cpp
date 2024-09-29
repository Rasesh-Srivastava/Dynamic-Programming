#include <bits/stdc++.h>
using namespace std;
// string x;
// string y;
// int dp[1000][1000];
// int LCS_length(int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }

//     if(x[n-1]==y[m-1]){
//         return dp[n][m]=1+LCS_length(n-1,m-1);
//     }
//     else{
//         return dp[n][m]=max(LCS_length(n-1,m), LCS_length(n,m-1));
//     }
// }
int main()
{
    string x,y;
    x="abcdgh";
    y="abedfhr";
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
    cout<<"ans is "<<dp[n][m]<<endl;
}