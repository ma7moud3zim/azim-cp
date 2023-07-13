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

void run(){

    ll n,k; 
    cin>>n>>k;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    ll dp[n+1]={};
    dp[0] = 0;
    for(int i=1; i<n;i++){
        dp[i] = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j>=0) dp[i] = min( dp[i] ,abs(a[i]-a[i-j])+dp[i-j]);
        }
    }

    cout<<dp[n-1]<<nl;
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