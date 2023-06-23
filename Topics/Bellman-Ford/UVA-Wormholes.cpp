#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================

ll n,m;
const int INF = INT_MAX;
vector<vector<pill>> adj;

// This is bellman-ford code with cycle detection

bool spfa(ll s, vector<ll>& d) {
    int sz = adj.size();
    d.assign(sz, INF);

    vector<ll> cnt(sz, 0);
    vector<bool> inq(n, false);
    queue<ll> q;
    d[s] = 0;
    q.push(s);
    inq[s] = 1;
    
    while (!q.empty()) {
        int v = q.front(); q.pop();
        inq[v] = 0;
        for (auto edge : adj[v]) {
            int to = edge.fs, len = edge.sc;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inq[to]) {
                    q.push(to); inq[to] = 1;
                    cnt[to]++;
                    if (cnt[to] > sz) 
                        return 0;  
                }
            }
        }
    }
    return 1;
}

void init(){
    cin>>n>>m;
    adj.clear();
    adj.resize(n);
}

void run(){
    init();
    for(int i=0;i<m; i++){
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].pb({v,c});
    }
       
    vector<ll> d;
    if(spfa(0,d)) cout<<"not possible"<<nl;
    else cout<<"possible"<<nl;
}

//====================
int main()
{

    cin.tie(0)->sync_with_stdio(0);

    ll t = 1;
    cin >> t;
    while (t--)
        run();
}