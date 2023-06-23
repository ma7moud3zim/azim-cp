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
ll n,monst;
const ll N = 1005;
ll a[N][2];
ll mem[N][10050];

ll sol(ll x, ll y){

	if(y >= monst) return 0;
    
	if(x >= n) return INT_MAX;

	ll &ret = mem[x][y];
	if(~ret) return mem[x][y];

	ret = min( a[x][1] + sol(x, y+a[x][0]) , sol(x+1, y) );
	return ret;
}


void run(){
	cin >> monst >> n;

    for (int i = 0; i < n; i++) 
        cin>>a[i][0]>>a[i][1];
        
    memset(mem, -1, sizeof mem);
    ll ans = sol(0,0);    

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