#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================
int mod=1e9+7; 

void run(){
      int n,k;
    cin >> n >> k;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int dp[n+1][k+1];
    
    memset(dp , 0 , sizeof dp);
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        int sums[k+1];
        sums[0]=dp[i-1][0];

        for(int j=1;j<=k;j++)
            sums[j] = (sums[j-1]+dp[i-1][j]) %mod;
        
        for(int j=0;j<=k;j++)
        {
            int tr=sums[j];  
            int unrch=j-a[i]-1;

            if(unrch>=0)
                tr= (tr-sums[unrch]+mod) %mod;
            
            dp[i][j]=tr;
        }
    }

  	cout << dp[n][k];
}





//=================================================
signed main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ll t=1; 
    // cin>>t;
    while(t--){
       run();
    }
}