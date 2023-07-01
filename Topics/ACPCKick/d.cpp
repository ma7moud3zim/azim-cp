#include <bits/stdc++.h>
#define nl '\n'
#define fast cin.tie(0)->sync_with_stdio(0);
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
void play()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
#ifndef ONLINE_JUDGE
    cout << "==========(input from file)==========" << nl;
    freopen("input.txt", "r", stdin);
#endif
}
ll tc;
//=====================================



void run()
{
    map<ll,set<ll> > x;
    map<ll,set<ll> > y;
    
    ll n; cin>>n;
    pill c;
    cin>>c.fs>>c.sc;

    x[c.fs].insert(c.sc);
    y[c.sc].insert(c.fs);
    
    bool f=1;
    for(int i=0; i<n; i++){
        ll u,v;
        cin>>u>>v;
        x[u].insert(v);
        y[v].insert(u);
        pill fk = {u,v};
        if(fk == c){
           f=0;
        }
    }

    pill strt = c;
    ll q;
    cin>>q;

    while(q--){
        char dr;
        cin>>dr;
        if(dr == 'U' || dr == 'D'){
            auto it = x[c.fs].find(c.sc);
            if(dr =='U'){
                if(it != (--x[c.fs].end())) it++ , c.sc = *it; 
            }else{
                if(it != x[c.fs].begin()) it-- , c.sc = *it; 
            }
        }else{
            auto it = y[c.sc].find(c.fs);
            if(dr =='R'){
                if(it != (--y[c.sc].end())) it++ , c.fs = *it; 
            }else{
                if(it != y[c.sc].begin()) it-- , c.fs = *it; 
            }
        }
        cout<<c.fs<<' '<<c.sc<<nl;

        if(c!=strt && f){
            x[strt.fs].erase(strt.sc);
            y[strt.sc].erase(strt.fs);
            f=0;
        }
    }

    
} 

//=====================================

signed main()
{

    // play();
    fast
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
}