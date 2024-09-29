#include <bits/stdc++.h>
using namespace std;
bool funct(int arr[], int n, int sum){
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
    return t[n][sum];
}
int main(){
    //int arr[]={1,6,11,5};
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int x=sum/2;
    for(; x<=sum;x++){
        if(funct(arr,n,x)==true){
            break;
        }
    }
    cout<<"Answer is "<<abs(2*x-sum)<<endl;

}