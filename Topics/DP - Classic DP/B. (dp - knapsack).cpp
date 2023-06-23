#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
//=================================================
ll n , W;
ll w[120] , v[120];
ll mem[120][100006];

ll cal(ll cur , ll _w){
    if(cur == n || _w > W)
        return 0;
    


    ll &ret = mem[cur][_w];
    if(~ret) return ret;

    if(_w + w[cur] > W){
        return ret = cal(cur+1 , _w);
    }
    return ret = max(v[cur] + cal(cur+1 , _w+w[cur]) , cal(cur+1 , _w)); 
}

void run(){
    cin>>n>>W;
    // we want to get max v with less w
    for(int i=0; i<n; i++){
        cin>>w[i]>>v[i];
    }
    memset(mem, -1 , sizeof mem);
    cout<<cal(0, 0);

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
    while(t--){
       run();
    }
}