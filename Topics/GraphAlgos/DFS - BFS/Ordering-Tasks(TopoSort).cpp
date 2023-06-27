#include <bits/stdc++.h>
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
vector<ll> ans;
vector<ll> vis;

void dfs(ll nd){
    vis[nd]=1;

    for(auto nx:gr[nd]){
        if(!vis[nx]) dfs(nx);
    }

    ans.pb(nd);
}
ll n,m;

void run()
{
    gr.resize(n);
    vis.resize(n);
    ll u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        gr[--u].pb(--v);
    }
    
    for(int i=0; i<n;i++){
        if(!vis[i]) dfs(i);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]+1;
        if((i+1)<ans.size()) cout<<' ';
    }

    ans.clear();
    gr.clear();
    vis.clear();
}

//====================
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll t = 1;
    // cin >> t;
    while (cin>>n>>m && n){
        run();
        cout<<nl;
    }
}