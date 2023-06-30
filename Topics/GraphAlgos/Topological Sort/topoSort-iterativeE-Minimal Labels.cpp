#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================
vector<vector<ll>> gr;
ll n,m;
vector<ll> ans;
ll vs[int(1e5+5)];
void dfs(ll nd){
	vs[nd] = 1;
	for(auto nx:gr[nd]){
		if(!vs[nx]) dfs(nx);
	}	
	ans.pb(nd);
}

void run()
{
	cin>>n>>m;
	gr.resize(n+1);
	
	ll outEdge[n+1]={};
	for(int i=0; i<m; i++){
		ll u,v;
		cin>>u>>v;
		outEdge[u]++;
		gr[v].pb(u);
	}
	set<ll,greater<>> st;
	for(int i=1;i<=n;i++){
		if(!outEdge[i])
			st.insert(i);
	}
	ll num = n;
	ll ans[n+1]={};

	while(st.size()){
		ll nd = *st.begin();
		st.erase(st.begin());
		ans[nd] = num--;
		for(auto nx:gr[nd]){
			outEdge[nx]--;
			if(!outEdge[nx] && !ans[nx])
				st.insert(nx);
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";

}	

//====================
int main()
{
#ifndef ONLINE_JUDGE
	freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
	cin.tie(0)->sync_with_stdio(0);
#endif

	ll t = 1;
	// cin >> t;
	while (t--)
		run();
}
