#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================

const int N = 755;
int n, m, par[N], cnt[N];

bool cmp(pair<ll, pair<int, int>> x,pair<ll, pair<int, int>> y){
    return x.fs < y.fs;
}

void init(int n)
{
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);
}
int findParent(int u)
{
    if (u == par[u])
        return u;
    return par[u] = findParent(par[u]);
}
bool join(int u, int v)
{
    u = findParent(u), v = findParent(v);
    if (u != v)
    {
        if (cnt[u] > cnt[v])
            swap(u, v);
        par[u] = v;
        cnt[v] += cnt[u];
        return 1;
    }
    return 0;
}

ll getDist(ll &x,ll &y,ll &x1, ll &y1){
    ll nx = x-x1, ny= y-y1;
    return ((nx*nx) + (ny*ny)); 
}


void run()
{
    ll n;
    cin >> n;
    ll x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    
    ll q;
    cin >> q;
    ll u, v;
    init(n);
    ll cnt = 0;
    for (int i = 0; i < q; i++){
        cin >> u >> v;

        cnt += join(u-1, v-1);
    }
    
    if (cnt >= n - 1){
        cout << "No new highways need" << nl;
    }
    else
    {
        vector<pair<ll,pill>> p;
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n;j++){
                p.push_back({getDist(x[i],y[i],x[j],y[j]) ,{i,j}});
            }
        }
        sort(p.begin(),p.end(),cmp);
        for(int i=0; i<p.size(); i++){
            int u = p[i].sc.fs;
            int v = p[i].sc.sc;
            if (findParent(u) != findParent(v)){
                join(u, v);
                cout<<u+1<<' '<<v+1<<nl;
            }
        }

    }
}

//====================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

    ll t = 1;
    cin >> t;
    while (t--){
        run();
        if(t) cout<<nl;
    }
}