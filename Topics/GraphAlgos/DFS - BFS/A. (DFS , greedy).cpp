#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================

int dx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int dy[] = { 0,-1, 1, 0, 1, -1 , 1,-1};

ll n , m;
string grid[30];
map<pill,bool> vis;

pill mag;
ll sz = 0;
char l;
void dfs(ll x, ll y ){
    vis[{x,y}];
    sz++;

    pill tm = {x,y};
    if(tm == mag){
        sz = INT_MIN;
    } 

    for(ll i=0; i<4; i++){
        ll xx = x+dx[i] , yy = y +dy[i];

        if(yy == m) yy = 0;
        if(yy == -1) yy = m-1;

        if(xx == -1 || xx == n) continue;

        if(!vis.count({xx,yy}) && grid[xx][yy] == l){
             dfs(xx, yy); 
        }
    }
}

void run(){

    for(int i=0; i<n; i++){
        cin>>grid[i];
    }
    cin>>mag.first>>mag.second;

    ll ans = 0;
    l = grid[mag.first][mag.second];

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            // cout<<grid[i][j];
            if(grid[i][j] == l && !vis.count({i,j})){
                dfs(i,j);
                ans = max(sz,ans);
                sz = 0;
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
    ll cn = 0;
    while(cin>>n>>m){
       vis.clear();
       run();
    }
}