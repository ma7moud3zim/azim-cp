#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define fs first
#define sec second
#define x fs
#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue;
#define br break;
#define cntpop __builtin_popcount
using namespace std;

void run(){
    ll n;
    cin>>n;
    ll prev = 1 , cur = -1;
    ll h[n]={};
    ll lst = 0;
    cin>>cur;
    for(int i=1; i<n; i++){
         cin>>cur;
         if(prev!=1 && cur < prev){
            lst++;
         }
         prev = cur;
         h[i] = h[lst]+1;
    }   
    cout<<h[n-1]<<nl;
}

signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ll t; cin>>t;
    while(t--){
        run();
    }
}