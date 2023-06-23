#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll> 
#define pb push_back
#define yn cout<<(ok ? "YES" : "NO")<<nl;
using namespace std;
//=================================================
const int N= 220;
int deg[N], fa[N], vis[N];
int n, m;

int find(int x)
{
    return fa[x] == -1 ? x : fa[x] = find(fa[x]);
}

void _union(int x, int y)
{
    int fx = find(x), fy = find(y);
	if (fx != fy)
        fa[fx] = fy;
    
}

bool check()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] && fa[i] == -1)
            res++;
    }

    if (res != 1)
        return false;
    

    for (int i = 0; i < n; i++)
    {
        if (vis[i] && (deg[i] & 1)) return false;
        
    }
    return true;
}

void run(){
	int u,v;
	while(m--){
		cin>>u>>v;
		_union(u,v);
		deg[u]++,deg[v]++;
		vis[u] = vis[v]=1;
	}
	
	cout<<(check()?"Possible":"Not Possible")<<nl;
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
		memset(deg, 0,sizeof deg);
    	memset(fa, -1,sizeof fa);
	    memset(vis, 0,sizeof vis);
	
		run();
    }
}