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
#define cont continue
#define br break;
#define cntpop __builtin_popcount
using namespace std;
const int MX = 2e5+5;
vector<vector<ll>> gr(MX);
ll clr[MX];

void dfs(ll nd , ll c,ll cur){
    vector<ll> tm;

    for(int i=1; tm.size()<gr[nd].size(); i++)
        if(i == cur || i == clr[nd]) cont;
        else tm.pb(i);
    
    ll pv=0;
    for(auto it:gr[nd]){
        if(it == c) cont;   
        clr[it] = tm[pv++]; 
        dfs(it,nd,clr[nd]);
    }
}

void run(){
    ll n;
    cin>>n;
    ll u,v;
    ll on = n;
    for(int i=0; i<n-1;i++){
        cin>>u>>v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    
    clr[1] = 1;
    dfs(1,-1,-1);
    
    cout<<*max_element(clr+1, clr+n+1)<<nl;
    for(int i=1; i<=on;i++){
        cout<<clr[i]<<' ';
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
    while(t--){
        run();
    }
}