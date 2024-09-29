/*Staring from 0th stair you have to reach the nth stair
You can make jump of 1 stair or 2 stair*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //T(n)=T(n-1)+T(n-2) T(1)=1 T(2)=2
    //number of ways to reach nth step is sum of number of ways to reach n-1th step and n-2th step
    // int c;
    // int a=1,b=2;
    // if(n==1 || n==2){
    //     cout<<n<<endl;
    //     return 0;
    // }
    // for(int i=0;i<=n-3;i++){
    //     c=a+b;
    //     a=b;
    //     b=c;
    // }
    // cout<<c<<endl;
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;

}