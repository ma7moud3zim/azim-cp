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

void run(){

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<n;i++) a[i] /= 2;
    
    ll lc = 1;
    
    for (auto a : a) {
        lc = lc * a / gcd(lc, a);
        if (lc > m) {
            return void(cout<<0<<nl);
        }
    }

    vector<ll> diff;
    for (auto _a : a)
    {
        if (lc / _a % 2 == 0) {
            return void(cout<<0<<nl);
        }
    }
    cout << 1 + (m - lc) / (lc * 2) << nl;

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