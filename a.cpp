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
// DP to count problem
// Using iterative approach
ll mod = 1e9+7;

void run(){
	ll n,x; 
	cin>>n>>x;
	ll cns[n];
	for(int i=0; i<n; i++) 
		cin>>cns[i];
	ll dp[x+1]={};
	dp[0] = 1;
	for(int i=0; i<=x;i++){
		if(dp[i]){
			for(int j=0; j<n; j++){
				if(i+cns[j]<=x)
					dp[i+cns[j]] += dp[i] ,dp[i+cns[j]]%=mod;
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