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
vector<int> adj[(int)2e5+5]; 
int a[(int)2e5+5];
int dp[(int)2e5+5][2];
ll n, cnt =0,tc;

int slv(int x,int lst){
    if(x == n-1) return lst;
    auto &ret = dp[x][lst];
    if(~ret) return ret;

    ret = lst + slv(x+1, 0);
    
    int val = a[x];
    auto itr = upper_bound(adj[val].begin() , 
                adj[val].end() , x);

    if(itr != adj[val].end()){  
        ret = max(ret , (*itr-x) + slv(*itr,1));
    }
    return ret;
}

void run()
{
    cin >> n;
    for(int i=0; i<=n; i++){
        adj[i].clear();
        dp[i][0] = dp[i][1] = -1;
    }
    
    for (ll i = 0; i < n; i++)
    {   
        cin >> a[i];
        adj[a[i]].pb(i);
    }

    cout<<slv(0,0)<<nl;

}

//====================
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("/home/proazim/Desktop/TestCases/s/out0000.txt", "r", stdin);
    freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

    ll t = 1;
    cin >> t;
    while (t--)
        run();
}