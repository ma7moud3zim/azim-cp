#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#include <ext/numeric>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
#define dep(x) \
    cout << #x << ": " << x << nl;
using namespace std;
void play()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
//=================================================
vector<vector<pair<ll,pill > > >gr;
bool vis[100005];
ll ans =0;

void dijkstra(){

    priority_queue<pair<ll,pair<ll,ll> > >pq;
    pq.push({0,{0,1}});

    while(pq.size()){
        ll city=pq.top().sc.fs;
        ll cur = pq.top().fs;
        ll ok=pq.top().sc.sc;
        pq.pop();
 
        if(vis[city])continue;
        vis[city]=true;
        if(!ok)ans++;

        for(auto nx:gr[city]){
            pq.push({cur - nx.sc.fs,
            {nx.fs,nx.sc.sc}});
        }
    }

}

void run()
{
    ll N,M,K;
    cin>>N>>M>>K;
    gr.resize(N+5);

    for(int i=0;i<M;i++){
        ll X,Y,Z;cin>>X>>Y>>Z;
        X--;Y--;
        gr[X].push_back({Y,{Z,1}});
        gr[Y].push_back({X,{Z,1}});
    }

    for(int i=0;i<K;i++){
        ll X,Z;
        cin>>X>>Z;
        X--;
        gr[0].push_back({X,{Z,0}});
    }

    dijkstra();
    cout<<K-ans<<nl;

}
 
//=================================================
signed main()
{
    play();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
}