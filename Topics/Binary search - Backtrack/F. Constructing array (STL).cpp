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
    ll n;
    cin>>n;
    map<ll,set<pill>> mp;
    set<ll> st;
    mp[n].insert({1,n});
    ll ans[n+1]={};
    st.insert({n});
    ll md ,cur;
    pill tm;
    ll cnt = 0;

    while(st.size()){
        cur = *st.rbegin();
        tm = *mp[cur].begin();

        md=(tm.fs + tm.sc) /2;
        ans[md] = ++cnt;
        mp[cur].erase(tm);
        if(md-tm.fs)
        {
            mp[md-tm.fs].insert({tm.fs , md-1});
            st.insert(md-tm.fs);
        }
        if(tm.sc-md)
        {
            mp[tm.sc-md].insert({md+1, tm.sc});
            st.insert(tm.sc-md);
        }

        if(mp[cur].empty()) st.erase(cur);
    }

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<nl;
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