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
	ll n,m;
	cin>>n>>m;
	ll dp[n+1][m+1]={};
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i==j) continue;
			dp[i][j] = INT_MAX;

			for(int i1=i-1; i1>=1;i1--){
				dp[i][j] = min(dp[i][j] , 
					1+dp[i1][j]+dp[i-i1][j]);
			}

			for(int j1=j-1; j1>=1;j1--){
				dp[i][j] = min(dp[i][j] , 
					1+dp[i][j1]+dp[i][j-j1]);
			}
		}

	}

	cout<<dp[n][m]<<nl;
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