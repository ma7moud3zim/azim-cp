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
    ll n,k;
    cin>>n>>k;

    vector<ll> prm;
    ll org = n;

    for(int i=2; i*i<=n; i++){
        while(org%i == 0) prm.pb(i) , org/=i;
    }
    if(org>1)prm.pb(org);

    if(prm.size() < k) return void(cout<<-1<<nl);
    ll sz = prm.size();
    ll pv = 1;
    for(auto p:prm){
        if(sz > k){
            pv *= p;
            sz--;
        }else{
            if(~pv){
                cout<<pv*p<<' ';
                pv = -1;
            }else cout<<p<<' ';
        }
    }
    cout<<nl;
    
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