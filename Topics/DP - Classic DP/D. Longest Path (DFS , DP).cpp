#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================
const ll mx = 1e5+5;
ll n ,m;
vector<ll> gr[mx];
ll mem[mx];

ll dfs(ll nd){
    ll ans = 0; 

    ll &ret = mem[nd];
    if(~ret) return ret; 

    for(auto nx:gr[nd]){
        ans =max(ans, 1 + dfs(nx));
    }
    return ret = ans;
}

void run(){
    cin>>n>>m;

    ll u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        gr[u].pb(v);    
    }

    ll ans = INT_MIN;
    memset(mem , -1 , sizeof mem);
    for(int i=1; i<=n;i++){
        ans = max(ans, dfs(i));
    }
    cout<<ans<<nl;
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