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
ll n,m,k;
const ll N = 72;
ll a[N][N];
ll mem[N][N][N / 2 + 1][N];

ll calc(ll x, ll y, ll cnt , ll mod){

    if (x == n)
        return mod == 0 ? 0 : INT_MIN;

    ll &ret = mem[x][y][cnt][mod];
	
    if (~ret)
        return ret;

    if (y == m)
        return ret = calc(x + 1, 0, m / 2, mod);

    ret = calc(x, y + 1, cnt, mod);

    if (cnt > 0)
        ret = max(ret, calc(x, y + 1, cnt - 1, (mod + a[x][y]) % k) + a[x][y]);
 
    return ret;

}


void run(){
	cin >> n >> m >> k;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
        
    memset(mem, -1, sizeof mem);
    
	cout << calc(0, 0, m / 2, 0)<<nl;
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