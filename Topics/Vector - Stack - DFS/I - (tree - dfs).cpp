#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define fs first
#define sec second
#define x fs
#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue;
#define br break;
#define cntpop __builtin_popcount
using namespace std;
const int mx = 1e5+5;
ll n,k;
vector<vector<ll>> tree (mx);
bool vis[mx] , cats[mx];
ll ans = 0;

void dfs(int nd, int cur){
    vis[nd] = true;

    // cout<<"This is cur " << cur <<" of node " << nd<<nl;
    if(cats[nd]) cur++;
    else cur = 0;
    if(cur > k) return;

    if(tree[nd].size() == 1 && nd != 1) ans++;

    for(auto it:tree[nd]){
        if(!vis[it]){
            // cout<<"from "<<nd<<" to "<<it<<nl;
            dfs(it,cur);
        }
    }
}

signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>cats[i];
    }

    ll u,v;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(1,0);
    cout<<ans<<nl;    
}