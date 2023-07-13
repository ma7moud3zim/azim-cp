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
/*This recursive solution also get AC.

bool dp[100][int(1e6+5)];
ll cns[100];
set<ll> ans;
ll n;

void rec(int i , int sum){	
	if(i==n){
		if(sum) ans.insert(sum);
		return;
	}

	auto &ret = dp[i][sum];
	if(dp[i][sum]) return;
	ret = 1;

	rec(i+1,sum+cns[i]);
	rec(i+1,sum);
}

void run(){
	cin>>n;
	for(int i=0; i<n; i++) cin>>cns[i];
	rec(0,0);
	cout<<ans.size()<<nl;
	for(auto i:ans) cout<<i<<' ';
	cout<<nl;
}
*/

void run(){
	ll n;
	cin>>n;
	ll cns[n];
	ll mx = 0;
	for(int i=0; i<n; i++) 
		cin>>cns[i],mx+=cns[i];
	ll dp[mx+1]={};
	dp[0]=1;
	sort(cns,cns+n);
	set<int> st;
	for(int i=0; i<n; i++){
		for(int j=mx; j>=cns[i]; j--){
			if(dp[j-cns[i]]){
				st.insert(j);
				dp[j] = 1;
			}
		}
	}
	cout<<st.size()<<nl;
	for(auto i:st)
		cout<<i<<' ';
	cout<<nl;
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