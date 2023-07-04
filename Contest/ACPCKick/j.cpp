#include <bits/stdc++.h>
#define nl '\n'
#define fast cin.tie(0)->sync_with_stdio(0);
#define ll long long
#define int long long
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
    ll n; cin>>n;
    vector<ll> a(n);
    ll prf[n+1];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    prf[n] = 0;
    for(int i=n-1;i>0; i--){
        prf[i] = max(a[i]-a[i-1] , prf[i+1]);
    }

    ll q;
    cin>>q;

    while(q--){
        ll cr ,x;
        cin>>cr>>x;
        ll ix = lower_bound(a.begin() , a.end() , cr) - a.begin();
        // cout<<ix<<' '<<prf[ix+1]<<' '<<x<<nl;

        bool ok = (prf[ix+1] <= x);
        yn
    }
    
} 

//=====================================

signed main()
{

    // play();
    // freopen("some.in" , "r",stdin);
    fast
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
}