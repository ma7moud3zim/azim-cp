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

void run(){
    ll n,k;
    cin>>n>>k;
    
    ll a[n+1]={} , prf[n+1] = {};

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+,a+n+1);

    for(int i=1;i<=n; i++)
        prf[i] =a[i]+prf[i-1];

    ll ans=0;
    ll cur=0,ad=0;

    // we can say you got the max subarray that hold for the condition
    for(int i=1;i<=n;i++)
    {
        while(i>cur && (a[i]*(i-cur))-(prf[i]-prf[cur]) > k)
            cur++;

        if((i-cur) > ad)
        {
            ad = i-cur;
            ans = a[i];
        }
    } 

    cout<<ad<<' '<<ans<<nl;
    
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