#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
//=================================================

int dx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int dy[] = { 0,-1, 1, 0, 1, -1 , 1,-1};

map<pill,vector<pill>> gr;
map<pill,bool>vis;

bool ok = false;
void dfs(pill x, pill trgt ){
    vis[x];
    if(x == trgt){
        ok = true;
        return;
    }

    for(auto it:gr[x]){
        if(!vis.count(it))dfs(it,trgt);
    }
}

void run(){

    ll n; cin>>n;
    ll op;
    vector<pill> all;
    
    while(n--){
        cin>>op;
        ll a,b;
        cin>>a>>b;
        if(op == 1){
            for(int i=0; i<all.size(); i++){
                ll c=all[i].first,d=all[i].second; 
                
                if( (c<a && a<d) || (c<b && b<d)){
                    gr[{a,b}].pb(all[i]);
                }   

                if((a<c && c<b) || (a<d && d<b)){
                    gr[all[i]].pb({a,b});
                }
            }

            all.pb({a,b});
        }else{  
            dfs(all[a-1],all[b-1]);
            yn
            ok = false;
            vis.clear();
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
    while(t--){
       run();
    }
}