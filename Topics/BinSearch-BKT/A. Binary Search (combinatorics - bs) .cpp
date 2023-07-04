#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================
ll MOD = 1e9+7;

void run(){
    ll n, x, pos;
    cin>>n>>x>>pos;
    
    ll l = 0, r = n;
    ll L = 0, R = 0;
    ll md;

    while (l < r) {
        md = (l + r) / 2;

        if (pos < md) r = md, ++R;
        else l = md + 1, L += (md != pos);
    }

    ll ans = 1;
    for (int i=1;i<=L;i++) ans = ans*(x-i) % MOD;
    for (int i=1;i<=R;i++) ans = ans*(n-x-i+1) % MOD;
    for (int i=1;i<(n-L-R);i++) ans = ans*i % MOD;

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