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
set<int> prime;
ll n;
ll cn = 0, ans[20] = {1};

void bkt(ll L, bool vis[])
{
    if (L == n) {
        if (!prime.count(ans[n-1] + 1)) 
            return;

        cout<<1;
        for (int i = 1; i < n; ++i)
            cout<<' '<<ans[i];

        cout<<nl;
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if (vis[i]) continue;
        
        if (prime.count(i + ans[L - 1])) {
            vis[i] = 1 , ans[L] = i;
            bkt(L + 1, vis);
            vis[i] = 0;
        }
    }
}

void run(){
    bool visit[20] = {0};
    bkt(1, visit);
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
    prime.insert({2,3,5,7,11,13,17,19,23,29,31,37,41});

    while(cin>>n){
       if(cn) cout<<nl;
       cout<<"Case "<<++cn<<':'<<nl; 
       run();
    }
}