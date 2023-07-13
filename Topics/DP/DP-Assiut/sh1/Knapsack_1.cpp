#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout<<#x<<": "<<x<<nl
using namespace std;
//============================
ll n , W;
ll w[101],v[101];
ll dp[101][100005];
/*
ll rec(int ix, ll we){
    if(ix == n){
        return 0;
    }
    auto &ret = dp[ix][we];
    if(~ret) return ret;
    
    if(we+w[ix]<=W) ret = v[ix]+rec(ix+1,we+w[ix]);
    ret = max(ret,rec(ix+1,we));

    return ret;
}
*/
void run(){
    cin>>n>>W;
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    
    // memset(dp,-1,sizeof dp);
    // cout<<rec(0,0)<<nl;

    ll dp[n+1][W+1] = {};
    
    for(int i=0; i<=W; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(j>=w[i-1])dp[i][j] = max(dp[i-1][j] ,v[i-1]+dp[i-1][j-w[i-1]]); 
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][W]<<nl;
}
//============================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
    ll t=1;
    // cin>>t;
    while(t--){
        run();
    }
}