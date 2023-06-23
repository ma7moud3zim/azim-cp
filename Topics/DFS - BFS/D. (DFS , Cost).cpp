#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll> 
#define pb push_back
#define yn cout<<(ok ? "Yes" : "No")<<nl;
using namespace std;
//=================================================
ll par[1005] , chld[1005];

map<pill,ll> dim;

vector<pair<ll,pill>> ans; 
pair<ll,pill> cur;

map<ll,ll>vis;

void dfs(ll par, ll nd,ll mn){
    if(vis.count(nd)) return;
    vis[nd];

    mn = min(mn, dim[{par,nd}]);   
    
    if(chld[nd] == -1) 
    {
        cur = {cur.first , {nd,mn}};
        ans.pb(cur);
        return;
    }
    dfs(nd,chld[nd],mn);
}

void run(){
    memset(par ,-1, sizeof par);
    memset(chld ,-1, sizeof chld);
    
    ll n,p; cin>>n>>p;
    ll u,v,d;
    while(p--){
        cin>>u>>v>>d;
        par[v] = u;
        chld[u] = v;

        dim[{u,v}]=d;
    }

    for(int i=1; i<=n; i++){
        if(par[i] == -1 && chld[i] != -1){
            vis[i];
            cur.first = i;
            dfs(i, chld[i],INT_MAX);
        }
    }

    cout<<ans.size()<<nl;
    for(auto [a,b]:ans){
        cout<<a<<' '<<b.first<<' '<<b.second<<nl;
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
    while(t--){
       run();
    }
}