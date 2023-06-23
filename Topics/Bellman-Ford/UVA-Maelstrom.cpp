// Bellman Solution

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll,ll> 
#define fs first 
#define sc second 
#define pb push_back
using namespace std;
//====================

ll n;
const int INF = INT_MAX;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  
                }
            }
        }
    }
    return true;
}


void run(){
    cin>>n;
    string sc; 
    adj.resize(n+1);
    for(int i=1;i<n; i++){
        for(int j=0; j<i; j++){
            cin>>sc;
            if(sc == "x") 
                continue;
            ll c = stoll(sc);
            adj[i].pb({j,c});
            adj[j].pb({i,c});
        }
    }
       
    vector<int> d;
    spfa(0,d);
    int ans =0;
    for(auto ds:d){
        if(ds != INT_MAX)
            ans = max(ans,ds);
    }
    cout<<ans<<nl;
}

int main()
{


    cin.tie(0)->sync_with_stdio(0);

    ll t=1;
    // cin >> t;
    while (t--)
        run();
}

// Dijkstra Solution

#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll,ll> 
#define fs first 
#define sc second 
#define pb push_back
using namespace std;
//====================
vector<vector<pair<ll,ll>>> gr;
ll n;
void dijkstra(vector<ll> &d){
    d.assign(n+2, 2147383647);
    set<pill> q;
    q.insert({0, 0});
    
    while (q.size()){
        ll cst = q.begin()->fs;
        ll v = q.begin()->sc;

        q.erase(q.begin());
        
        if (d[v] < cst)
            continue;
        
        for (auto [nd, len] : gr[v]){
            if ((cst + len) < d[nd]){
                d[nd] = cst + len;
                q.insert({d[nd], nd});
            }
        }
    }
}   


void run(){
    cin>>n;
    string sc; 
    gr.resize(n+1);
    for(int i=1;i<n; i++){
        for(int j=0; j<i; j++){
            cin>>sc;
            if(sc == "x") 
                continue;
            ll c = stoll(sc);
            gr[i].pb({j,c});
            gr[j].pb({i,c});
        }
    }
       
    vector<ll> d;
    dijkstra(d);
    ll ans =0;
    for(auto ds:d){
        if(ds != 2147383647)
            ans = max(ans,ds);
    }
    cout<<ans<<nl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

    ll t=1;
    // cin >> t;
    while (t--)
        run();
}