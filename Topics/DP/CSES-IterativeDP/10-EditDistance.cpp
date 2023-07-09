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
	string a,b;
	cin>>a>>b;
	ll n =a.size();
	ll m = b.size();
	ll dp[n+1][m+1]={};
	for(int i=0; i<=n; i++)
		dp[i][0] = i;
	for(int i=0; i<=m; i++)
		dp[0][i] = i;

	for(int i=1; i<=n;i++){
		for(int j=1; j<=m; j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] =1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
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