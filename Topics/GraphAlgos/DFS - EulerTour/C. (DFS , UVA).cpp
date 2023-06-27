#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll> 
#define pb push_back
#define yn cout<<(ok ? "YES" : "NO")<<nl;
using namespace std;
//=================================================
const int mx = 1e6+4;
vector<int> gr[mx];
ll n,m; 
vector<int> ans;
map<ll,bool> vis;
bool imp = false;
ll cycl[mx];
ll mrk;

void dfs(int nd){		
	if(vis.count(nd)) return;
	if(cycl[nd] == mrk) return void(imp = 1);
	cycl[nd] = mrk;
	for(auto it:gr[nd]){
		if(imp) return;
		dfs(it);
		cycl[it] = mrk;
	}

	vis[nd];
	ans.pb(nd);
}

void run(){ 
	ll u,v;
	for(int i=0;i<=n;i++)
			gr[i].clear();

	while(m--){
		cin>>u>>v;
		gr[v].pb(u);
	}

	imp = false;
	for(int i=1; i<=n;i++){
		++mrk;
		dfs(i);
		if(imp) break;
	}

	if(imp) return void(cout<<"IMPOSSIBLE"<<nl);

	for(auto it:ans){
		cout<<it<<nl;
	}
}

//=================================================

signed main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ll t=1; 
    // cin>>t;
    while(cin>>n>>m){
			
			if(n==0 && m==0)break; 
      vis.clear();
			ans.clear();			
			run();
    }
}