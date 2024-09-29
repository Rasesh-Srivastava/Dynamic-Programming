//Determines if it is possible to divide the array into two partitions 
//such that sum of each partition is equal to other
#include <bits/stdc++.h>
using namespace std;
int main(){
    // int arr[]={2,3,7,8,10};
    int arr[]={2,3,7,8,11};
    int sum=0;
    
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if(sum%2!=0){
        cout<<"false";
        return 0;
    }
    sum=sum/2;
    bool t[n+1][sum+1];
    // check if a given sum is present
    for(int i=0;i<=n;i++){
        t[i][0]=true;
    }
    for(int j=1;j<=sum;j++){
        t[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]=( t[i-1][j-arr[i-1]] )|| ( t[i-1][j] );
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    if(t[n][sum]){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}