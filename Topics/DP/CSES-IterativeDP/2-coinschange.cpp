#include <bits/stdc++.h>
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
	ll n,x; 
	cin>>n>>x;
	ll cns[n];
	for(int i=0; i<n; i++) 
		cin>>cns[i];
	ll dp[x+1];
	memset(dp ,-1, sizeof dp);
	dp[0] = 0;
	
	for(int i=0; i<=x;i++){
		if(~dp[i]){
			for(int j=0; j<n; j++){
				if(i+cns[j]<=x){
					if(dp[i+cns[j]]==-1) dp[i+cns[j]] = INT_MAX;
					dp[i+cns[j]] = min(dp[i]+1,dp[i+cns[j]]);
				}
			}
		}
	}

	cout<<dp[x]<<nl;
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