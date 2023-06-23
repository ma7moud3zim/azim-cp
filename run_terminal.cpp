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
    vector<bool> inq(n, false);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    inq[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inq[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.fs;
            int len = edge.sc;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inq[to]) {
                    q.push(to);
                    inq[to] = true;
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