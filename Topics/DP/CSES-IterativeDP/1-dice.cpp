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
ll mod=1e9+7;
void run(){
	ll n; cin>>n;
	ll dp[n+1]={};
	dp[0] = 1;

	for(int i=0; i<n;i++){
		for(int j=1; j<=6;j++){
			if(i+j<=n) dp[i+j] +=dp[i] , dp[i+j]%=mod; 
		}
	}
	cout<<dp[n]<<nl;
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