#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#include<ext/numeric>
#define nl '\n'
#define ll long long 
#define ld long double
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
using namespace __gnu_cxx;
void play(){
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
//=================================================

ll mod = 1e9+7;
ll MOD = 1e9+7;

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { 
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; 
    }
    return result;
}

ll powmod( ll b, int p, int m )
{
    ll r = 1;
    
    for(ll i=(1<<30); i; i>>=1)
    {
        r *= r; r %= m;
        if( p & i ){ r *= b; r %= m; }
    }
    
    return r;
}

ll divide(ll a, ll b){
    return a*fast_power(b,mod-2)%mod;
}

void run()
{   
    ll n; cin>>n;
    ll a[n];
    ll lc = 1;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
        // division
        // lc = a[i] / gcd(a[i],lc) * lc ;
        ll val = a[i]*lc % mod;
        lc = divide(val , gcd(a[i],lc));
    }

    ll sum =0;
    for(int i=0; i<n; i++){
        // division
        cout<<lc << ' '<<a[i]<<nl;
        // sum += lc/a[i];
        sum = (sum + divide(lc,a[i])) %mod;
    }

    cout<<sum%mod<<nl;

}


//=================================================
signed main()
{
    play();
    ll t=1; 
    // cin>>t;
    while(t--){
        run();
    }
}