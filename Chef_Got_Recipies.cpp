#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int f[32]={0};
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            int mask=0;
            for(char c:s){
                if(c=='a'){
                    mask=mask | (1<<0);
                }
                if(c=='e'){
                    mask=mask | (1<<1);
                }
                if(c=='i'){
                    mask=mask | (1<<2);
                }
                if(c=='o'){
                    mask=mask | (1<<3);
                }
                if(c=='u'){
                    mask=mask | (1<<4);
                }
            }
            f[mask]++;
        }
        int ans=0;
        for(int i=0;i<32;i++){
            for(int j=i+1;j<32;j++){
                if( (i | j)==31){
                    if(i!=j) ans+=f[i]*f[j];
                    else ans+=(f[i]*(f[j]-1))/2;
                }
            }
        }
        cout<<ans<<endl;
        // for(int i=0;i<32;i++){
        //     cout<<f[i]<<endl;
        // }
    }
    
    
    return 0;
}