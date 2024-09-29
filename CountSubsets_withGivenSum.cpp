//Counts the number of distinct subsets of the araay with given sum
#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,3,7,8,10};
    int sum;
    cin>>sum;
    int n= sizeof(arr)/sizeof(arr[0]);
    int t[n+1][sum+1];
    // check if a given sum is present
    for(int i=0;i<=n;i++){
        t[i][0]=1;
    }
    for(int j=1;j<=sum;j++){
        t[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] + t[i-1][j];  //we have to add as we have to keep going and add;
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][sum];
}