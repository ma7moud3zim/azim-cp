#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define pii pair<int, int>
#define fs first
#define sec second
#define x fs
#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue
#define br break;
#define cntpop __builtin_popcount
using namespace std;
// directions 
int dx[]={-1,-1,-1,0,1,1,1,0},
    dy[]={-1,0,1,1,1,0,-1,-1};


const int mx = 1e5+5;
vector<vector<int>> gr(mx);
bool vis[mx];


ld dfs(int i){
    vis[i] = true;
    ld sum = 0;
    for(auto nd: gr[i]){
        // cout<<i<<' '<<nd<<nl;
        if(!vis[nd]){
            sum += dfs(nd)+1;
        }
    }
    return sum?sum/(gr[i].size()-(i != 1)) : 0;
}

void run(){
    ll n; cin>>n;
    if(n == 1){
        cout<<0<<nl;
        return;
    }

    ll u,v;
    n--;
    while(n--){
        cin>>u>>v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    ld res = dfs(1);
    cout<<fixed<<setprecision(8)<<res<<nl;
}

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