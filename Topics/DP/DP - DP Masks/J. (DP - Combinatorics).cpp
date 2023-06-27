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
ll MOD = 1e8;
ll f,h,_h,_f;
ll mem [101][101][11][11];

ll sol(ll f, ll h,ll ff , ll hh){

	if((f+h) == 0) return 1;

    ll &ret = mem[f][h][ff][hh];
    
    if(~ret) 
        return ret;
    
    ll x=0,y=0;

    if(f > 0 && ff > 0) x = sol(f-1,h,ff-1,_h);

    if(h > 0 && hh > 0) y = sol(f,h-1,_f,hh-1);
    
    return ret = (x+y)%MOD;
}


void run(){

    cin>>f>>h>>_f>>_h;

    memset(mem, -1, sizeof mem);
    ll ans = sol(f,h,_f,_h);    

    cout<<ans<<nl;
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