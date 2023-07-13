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

    ll n; 
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    ll dp[n+1]={};
    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);
    for(int i=2; i<n;i++){
        dp[i] = min( abs(a[i]-a[i-1])+dp[i-1] ,abs(a[i]-a[i-2])+dp[i-2]);
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