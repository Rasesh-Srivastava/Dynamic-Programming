#include <bits/stdc++.h>
using namespace std;
int t[1000][1000];
int knapsack(int weight[], int value[], int n, int w){
    //memoization
    if(n==0|| w==0){
        return 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(weight[n-1]<=w){
        // either include or not
        t[n][w]=max(value[n-1]+ knapsack(weight,value,n-1,w-weight[n-1]),knapsack(weight,value,n-1,w));
        return max(value[n-1]+ knapsack(weight,value,n-1,w-weight[n-1]),knapsack(weight,value,n-1,w));
    }
    else{
        t[n][w]=knapsack(weight,value,n-1,w);
        return knapsack(weight,value,n-1,w);
    }
}

int main()
{
    int value[]={30,44,20,18};
    int weight[]={5,11,4,2};
    int W=16;
    int n=sizeof(value)/sizeof(value[0]);
    memset(t,-1,sizeof(t));
    cout<<knapsack(weight,value,n,W)<<endl;
    return 0;
}