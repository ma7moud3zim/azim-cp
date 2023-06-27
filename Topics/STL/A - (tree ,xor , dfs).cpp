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
ll n;
vector<vector<ll>> tree (mx);
bool cur[mx] , goal[mx];
bool vis[mx];

vector<ll> ans;

void dfs(int nd , bool ev, bool od,int lv){
    vis[nd] = true;
    
    if(lv%2){
        if(od){
            cur[nd] = !cur[nd];
        }
        if(cur[nd] != goal[nd]){
            ans.pb(nd);
            od = !od;
        }
    }else{
        if(ev){
            cur[nd] = !cur[nd];
        }

        if(cur[nd] != goal[nd]){
            ans.pb(nd);
            ev = !ev;
        }
    }

    for(auto it:tree[nd]){
        if(!vis[it]){
            // cout<<it<<nl;
            dfs(it,ev,od,lv+1);
        }
    }
}

signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("file.txt", "r", stdin);
#endif

    cin>>n;
    ll u,v;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    for(int i=1;i<=n; i++) cin>>cur[i];
    for(int i=1;i<=n; i++) cin>>goal[i];

    dfs(1 , false,false , 0);
    cout<<ans.size()<<nl;

    for(auto it:ans) cout<<it<<nl;
    
}