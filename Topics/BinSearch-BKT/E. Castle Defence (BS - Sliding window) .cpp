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
#define yn cout << (ok ? "Yes" : "No") << nl;
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
ll n,rng,k, md;
ll a[int(5*1e5+5)];

bool chk() {
    ll cur [n+1];
    memcpy(cur , a , sizeof cur);
    ll sum = 0;
    pill window = {0,-1};
    ll needed = 0;

    for (int i = 0; i < n; i++) {
        if (needed > k) return 0;
        
        while (window.sc < n-1 && window.sc < i + rng) 
            window.sc++ ,sum += cur[window.sc];

        while (window.fs < i - rng) 
            sum -= cur[window.fs] , window.fs++;
        
        if (sum < md) {
            needed += md - sum;
            cur[min(i + rng,n-1)] += (md - sum);
            sum = md;
        }
    }
 
    return needed <= k;
}

void run(){
    cin>>n>>rng>>k;
    for(int i=0; i<n;i++) cin>>a[i];

    ll l = 0 , r=LLONG_MAX;
    ll ans = -1;

    while(l<=r){
        md = (l+r)/2;

        if(chk()) ans = md , l = md+1;
        else r = md-1;
    }

    cout<<ans<<nl;
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