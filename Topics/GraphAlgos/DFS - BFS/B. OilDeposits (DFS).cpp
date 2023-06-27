#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1,-1, -1};

ll n , m;
string grid[102];
map<pill,bool> vis;

bool valid(ll x, ll y){
    return !vis.count({x,y}) && x >= 0 && y>=0 && x<n && y<m && grid[x][y] == '@';
}

void dfs(ll x, ll y){
    vis[{x,y}];

    for(ll i=0; i<8; i++){
        if(valid(x+dx[i],y+dy[i])) dfs(x+dx[i] , y+dy[i]); 
    }
}

void run(){
    for(int i=0; i<n; i++){
        cin>>grid[i];
    }
    ll ans =0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(grid[i][j] == '@' && !vis.count({i,j})){
                // cout<<i<<' '<<j<<nl;
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<nl;
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
    while(t){
        vis.clear();
       cin>>n>>m;
       if(m == 0) break;
       run();
    }
}