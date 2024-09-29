#include <bits/stdc++.h>
using namespace std;
int maxi(int a, int b){
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}
int main()
{
    int value[]={60,100,120};
    int weight[]={10,20,30};
    int W=50;
    int n=sizeof(value)/sizeof(value[0]);
    int t[n+1][W+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(weight[i-1]<=j){
                t[i][j]=max( value[i-1]+t[i-1][j-weight[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][W]<<endl;
}