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
    int sumt=accumulate(arr,arr+n,0);
    int diff=1;
    //s1-s2=diff;
    //s1+s2=sumt;
    //s1=(diff+sumt)/2;
    //s2=(-diff+sumt)/2;
    if( (sumt+diff)%2!=0 || (sumt-diff)%2!=0){
        cout<<0<<endl;
    }
    int s1=(diff+sumt)/2;//p
    //ans=p*q
    /*Problem reduced to finding number of subsets with sum=s1*/
    int p=Number_Of_Subsets_With_Given_Sum(arr,n,s1);
    //int q=Number_Of_Subsets_With_Given_Sum(arr,n,s2);
    cout<<p<<endl;
    return 0;

}