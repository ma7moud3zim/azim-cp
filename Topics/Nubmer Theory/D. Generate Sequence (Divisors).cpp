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
    ll n;
    cin>>n;

    map<ll,ll> prm;
    ll org = n;

    for(ll i=2; i*i<=n; i++){
        while(org%i == 0) prm[i]++ , org/=i;
    }
    if(org>1)prm[org]++;
    
    vector<ll> ans;
    ll cur =2;

    while(cur>1){
       cur=1;
       for(auto &[p,fr]:prm){
            if(fr > 0){
               cur *=p; 
               fr--;
            }
       }
       if(cur>1) ans.pb(cur);
    }

    cout<<ans.size()<<nl;
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<' ';
    cout<<nl;
    
}

//=================================================
signed main()
{
    play();
    ll t=1; 
    cin>>t;
    while(t--){
        run();
    }
}