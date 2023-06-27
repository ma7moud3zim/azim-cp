#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define int long long 
#define pill pair<ll,ll> 
#define pb push_back
#define yn cout<<(ok ? "YES" : "NO")<<nl;
using namespace std;
//=================================================
const int N = 1e6;
bool vis[N], valid[N];
vector<int> gr[N];
ll cyc, cnt[N];
 
void dfs(int nd) {
    if (vis[nd]) return;
    vis[nd] = true;

    for (auto nxt: gr[nd])
        dfs(nxt);
}

void run(){
	int n, m;
    cin >> n >> m;
 
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b; 
		a--, b--;
        gr[a].pb(b),gr[b].pb(a);
        valid[a] = valid[b] = 1;
        
		if (a == b)
            cyc++;
        else
            cnt[a]++, cnt[b]++;
    }
 
    dfs(0);
    bool con = true;
 
    for (int i = 0; i < n; i++)
        if (valid[i]) {
            dfs(i);
            break;
        }
 
    for (int i = 0; i < n; i++)
        con &= vis[i] || !valid[i];
 
    if (!con) {
        cout << "0\n";
        return;
    }
 
    ll ans = cyc * (m - 1) - cyc * (cyc - 1) / 2;
 
    for (int i = 0; i < n; i++) {
        ans += (cnt[i]) * (cnt[i] - 1) / 2;
    }
 
    cout << ans << '\n';

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
	while(t--){
		run();
    }
	
}