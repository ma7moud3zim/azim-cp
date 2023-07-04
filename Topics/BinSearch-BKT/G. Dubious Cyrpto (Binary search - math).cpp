#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#include<ext/numeric>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
using namespace __gnu_cxx;
//=================================================


void run(){
    // try to make this code better I know it can be
    ll lw,hi,m;
    cin>>lw>>hi>>m;

    pill ndf = {INT_MAX,0} , df = {INT_MAX,0};
    ll md;
    ll i = lw , j = hi;

    while(i<=j){
        ll l = 1,r = 1e11;
        while(l<=r){

            md = (l+r)/2;

            if(i*md == m){
                cout<<i<<' '<<i <<' '<<i<<nl;
                return;
            }

            if(i*md > m){
              if(ndf.fs > i*md-m)
                ndf = { i*md-m,i};                
                r = md-1;
            }else{
                if(df.fs > m-i*md)
                     df = { m-i*md,i};
                l = md+1;
            }
        }
        i++;
    }

    if(df.fs > ndf.fs){
         cout<<ndf.sc<<' '<<hi-ndf.fs<< ' '<<hi<<nl;
    }else{
        cout<<df.sc<<' '<<hi<< ' '<<hi-df.fs<<nl;
    }
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
    cin>>t;
    while(t--){
       run();
    }
}