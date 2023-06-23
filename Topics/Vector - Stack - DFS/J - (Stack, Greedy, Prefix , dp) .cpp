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
#define cont continue
#define br break;
#define cntpop __builtin_popcount
using namespace std;

void run(){
    ll n;
    cin>>n;
    ll arr[n]= {};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<ll> l(n,-1) ,  r(n,n);    
    stack<ll> stk;
    ll ans[n+1] ={};

    for(int i=0; i<n; i++){
        while(stk.size() && arr[stk.top()] >= arr[i])
            stk.pop();
        if(stk.size()) 
            l[i] =stk.top();
        stk.push(i);
    }
    for(int i=0; i<n; i++) cout<<l[i]<<' ';
    cout<<nl;

    while(stk.size()) stk.pop();

    for(int i=n-1; i>=0; i--){
        while(stk.size() && arr[stk.top()] >= arr[i])
            stk.pop();

        if(stk.size()) 
            r[i] =stk.top();
        stk.push(i);
    }

    for(int i=0; i<n; i++){
        ll cur = r[i] - l[i] -1;
        ans[cur] = max(ans[cur] , arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        ans[i] = max(ans[i] , ans[i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<nl;
}

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