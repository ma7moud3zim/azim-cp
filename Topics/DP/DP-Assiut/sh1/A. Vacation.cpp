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
    ll a[n],b[n],c[n];
    for(int i=0; i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    ll dp[n+1][3]={};
    for(int i=1; i<=n; i++){
        dp[i][0] = a[i-1]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i-1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i-1]+max(dp[i-1][1],dp[i-1][0]);
    }

    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<nl;
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