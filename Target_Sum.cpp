/*Given array assign +/- operator to each value of the array 
such that arraysum becomes equal to given sum*/
/*Similar to previous problem with diff being sum in this problem*/
#include <bits/stdc++.h>
using namespace std;
int Number_Of_Subsets_With_Given_Sum(int arr[], int n, int sum){
    int t[n+1][sum+1];
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
    return t[n][sum];
}
int main()
{
    int arr[]={1,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=accumulate(arr,arr+n,0);
    int targetsum=1;
    if((targetsum+sum)%2!=0){
        cout<<"0"<<endl;
    }
    int s1=(targetsum+sum)/2;
    cout<<Number_Of_Subsets_With_Given_Sum(arr,n,s1)<<endl;
}
