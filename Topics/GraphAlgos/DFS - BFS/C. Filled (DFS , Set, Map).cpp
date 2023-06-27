#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================

int dx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 1,0, 1, -1,1, -1};



ll n , m;
string grid[50];
map<pill,bool> vis;
set<ll> st;
map< ll , multiset<char> > ans;

bool valid(ll x, ll y,char cur){
    return !vis.count({x,y}) && x >= 0 && y>=0 && x<n && y<m && grid[x][y] == cur;
}

ll sz = 0;
void dfs(ll x, ll y ,char cur){
    vis[{x,y}];

    for(ll i=0; i<4; i++){
        if(valid(x+dx[i],y+dy[i] ,cur)) sz++ , dfs(x+dx[i] , y+dy[i],cur); 
    }

}

void run(){
    for(int i=0; i<n; i++){
        cin>>grid[i];
    }
    sz = 1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(grid[i][j] != '.' && !vis.count({i,j})){

                dfs(i,j,grid[i][j]);

                st.insert(sz);
                ans[sz].insert(grid[i][j]);
                sz = 1;
            }
        }
    }

    for(auto it = st.rbegin(); it != st.rend(); it++){
        for(auto ss : ans[(*it)]){
            cout<<ss<<' '<<*it<<nl;
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

    ll t=1; 
    // cin>>t;
    ll cn = 0;
    while(t){
       vis.clear();
       st.clear();
       ans.clear();
       cin>>n>>m;
       if(n == 0 && m == 0) break;
       cout<<"Problem "<<++cn<<':'<<nl;
       run();
    }
}