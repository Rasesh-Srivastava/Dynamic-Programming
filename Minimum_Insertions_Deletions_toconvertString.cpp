/*
Input : 
str1 = "heap", str2 = "pea" 
Output : 
Minimum Deletion = 2 and
Minimum Insertion = 1
Explanation:
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.
*/
#include <bits/stdc++.h>
using namespace std;
string lcs(string x, string y){
    int n=x.size();
    int m=y.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=-1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
            }
        }
    }
    string ans="";
    int i=n;
    int j=m;
    while(i>=1&&j>=1){
        if(x[i-1]==y[j-1]){
            ans=ans+x[i-1];
            i--;
            j--;
            continue;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
            continue;
        }
        else{
            i--;
            continue;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void convert(string a,string b){
    int m=a.size();
    int n=b.size();
    int lcslen=lcs(a,b).size();
    cout<<"Insertions: "<<n-lcslen<<endl;
    cout<<"Deletions: "<<m-lcslen<<endl;
}
int main()
{
    string a,b;
    cin>>a>>b;
    convert(a,b);
}