/*Given some coins of different denominations and a sum, compute minimum number of coins needed to make that sum
approach: 
dp[sum+1]
where dp[i] denotes minimum number of coins needed to make sum =i;

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            dp[i]=1000000000;
            int ans=1000000000;
            bool found=false;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    ans=min(ans,dp[i-coins[j]]);
                    found=true;
                }
            }
            if(found==true) ans++;
            dp[i]=ans;
            
        }
        if(dp[amount]==1000000000 || dp[amount]==1000000001){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};
int main()
{
    
}