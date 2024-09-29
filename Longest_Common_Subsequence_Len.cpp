#include <bits/stdc++.h>
using namespace std;
string x;
string y;

int LCS_length(int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        return 1 + LCS_length(n-1,m-1);
    }
    else{
        return max(LCS_length(n-1,m), LCS_length(n,m-1));
    }
}
int main()
{
    x="abcdgh";
    y="abedfhr";
    int n=x.size();
    int m=y.size();
    cout<<LCS_length(n,m);
}