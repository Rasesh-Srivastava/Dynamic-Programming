/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence
 of a given sequence such that all elements of the subsequence are sorted in increasing order.
 For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 
 and LIS is {10, 22, 33, 50, 60, 80}.


 If we closely observe the problem then we can convert this problem to longest Common Subsequence
  Problem. Firstly we will create another array of unique elements of original array and sort it.
   Now the longest increasing subsequence of our array must be present as a 
   subsequence in our sorted array. That’s why our problem is now reduced to 
   finding the common subsequence between the two arrays. 
*/
#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int brr[];//arr[] sorted
int dp[1000][1000];
int lis(int n, int m){
    if(n==0|| m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(arr[n-1]==brr[m-1]){
        return dp[n][m]=lis(n-1,m-1)+1;
    }
    else{
        return dp[n][m]=max(lis(n-1,m), lis(n,m-1));
    }
}
int main()
{
    int n;
    //input array and size of array
    cout<<lis(n,n)<<endl;
    //accomplished in O(n*n)
}