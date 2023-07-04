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
//=================================================
ll n;
string s;
pill prf[(int)1e5+5];

map<char,pill> dir;
pill st, trg;
ll md;
int dx[] = {0,-1, 0, 0, 1, 1,-1,-1, 1};
int dy[] = {0, 0,-1, 1, 0, 1,-1, 1,-1};

bool chk(){
    ll x = st.fs , y = st.sc;

    x += (md/n)*prf[n].fs + (prf[md%n].fs);
    y += (md/n)*prf[n].sc + (prf[md%n].sc);


    return (abs(trg.fs-x)+abs(trg.sc-y)) <= md;
}

void run(){
    cin>>st.fs>>st.sc;
    cin>>trg.fs>>trg.sc;
    cin>>n;
    cin>>s;
    
    for(int i=1; i<=n; i++){
        prf[i].fs = dir[s[i-1]].fs + prf[i-1].fs;
        prf[i].sc = dir[s[i-1]].sc + prf[i-1].sc;
    }
    ll l = 0 , r=1e15;
    ll ans = -1;

    while(l<=r){
        md = (l+r)/2;

        if(chk()) ans = md , r = md-1;
        else l = md+1;
    }

    cout<<ans<<nl;
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
    dir['U'] = {0,1};
    dir['D'] = {0,-1};
    dir['L'] = {-1, 0};
    dir['R'] = {1,0};
    ll t=1; 
    // cin>>t;
    while(t--){
       run();
    }
}