#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll int 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
//=================================================
ll n,_cnv; 
ll a[203],b[203];
string s,sb;
ll mem[203][203][203];
ll rt =0;

ll calc(ll cur , ll cnv , ll aa){
    if(cur == n)
        return 0;

    ll &ret= mem[cur][aa][cnv];
    if(~ret) return ret;

    ll _ret = calc(cur+1, cnv, aa + (s[cur] == sb[0])) + aa * (s[cur] == sb[1]);

    if (cnv) {
        if (sb[0] == sb[1]) {
            if (s[cur] != sb[0])
                _ret = max(_ret, calc(cur+1, cnv - 1, aa + 1) + aa);
        }
        else if (s[cur] == sb[0])
            _ret = max(_ret, max(calc(cur+1, cnv, aa + 1), calc(cur + 1, cnv - 1, aa) + aa));
        else if (s[cur] == sb[1])
            _ret = max(_ret, max(calc(cur+1, cnv - 1, aa + 1), calc(cur + 1, cnv, aa) + aa));
        else
            _ret = max(_ret, max(calc(cur+1, cnv - 1, aa + 1), calc(cur + 1, cnv - 1, aa) + aa));
    }

    return ret = _ret;
}

void run(){
    cin>>n>>_cnv;
    cin>>s;
    cin>>sb; 
    n = s.size();
    

    memset(mem , -1,sizeof mem);
    ll ans= calc(0,_cnv,0);

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