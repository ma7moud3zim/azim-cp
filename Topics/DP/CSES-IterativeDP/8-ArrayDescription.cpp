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
const int mod = 1e9+7;
ll dp[int(1e5+1)][1001];

void run(){
    int n,m;
    cin>>n>>m;
	ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    if(a[0]) dp[0][a[0]] = 1;
    else for(int i=1; i<=m; i++) dp[0][i] =1;
    
    for(int i=1; i<n; i++){
        if(a[i]){
            ll j = a[i];
            if(j-1>=1) (dp[i][j]+=dp[i-1][j-1])%=mod;
            (dp[i][j] += dp[i-1][j])%mod;
            if(j+1<=m) (dp[i][j] += dp[i-1][j+1])%=mod;
        }else{
            for(int j=1; j<=m; j++){
                if(j-1>=1) (dp[i][j]+=dp[i-1][j-1])%=mod;
                (dp[i][j] += dp[i-1][j])%mod;
                if(j+1<=m) (dp[i][j] += dp[i-1][j+1])%=mod;
            }   
        }
    }
    
    ll tot =0;
    for(int i=1; i<=m; i++)
        (tot += dp[n-1][i])%=mod;
    
    cout<<tot<<nl;
    
}
//============================
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("/input.txt", "r", stdin);
    freopen("/home/proazim/Downloads/test_input (1).txt", "r", stdin);
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