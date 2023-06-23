// F div3

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


signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("file.txt", "r", stdin);
#endif
    ll t;cin>>t;
    map< int , pill> mp;
    
    while(t--){
        string str;
        cin>>str;
        int num =0;
        bitset<28> nm(0);
        bitset<28> nm2(0);
        for(int i=0; i<str.size(); i++){
            nm[str[i]-'a'].flip();
            nm2[str[i]-'a']=1;
        }

        ll xr = nm.to_ullong();
        ll rr = nm2.to_ullong();

        mp[nm.to_ullong()].fs++;

    }


    ll ans =0;
    map<pill,ll> vis;
    ll msk = pow(2,25)-  1;
    for(auto [cur,fr]:mp){
        bitset<28> stm2(cur);
        cout<<"cur "<<stm2<<nl;
        int nm = cur ^ msk;
        bitset<28> stm(nm);
        cout<<"Target "<<stm<<nl;
        bitset<28> msks(msk);
        cout<<"Msk "<<msks<<nl;

        if(mp.count(nm)){
            cout<<"Valid"<<nl;
            cout<<"cur valid "<<stm2<<nl;
            cout<<"target valid "<<stm<<nl;
            cout<<"============="<<nl;
            ans+= (fr*mp[nm]);
            vis[{cur,nm}];
            vis[{nm,cur}];
        } 
    }
    
    cout<<ans<<nl;

}