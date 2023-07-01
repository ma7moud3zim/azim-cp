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

ll mem[(int)1e5+5][2];


void run()
{
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> ng,ps;
    for(int i=0; i<n; i++){
        cin>>tc;
        if(tc<0) ng.pb(tc);
        else ps.pb(tc);
    }
    if(k>=ng.size()){
        // Todo
    }
    sort(ng.rbegin() , ng.rend());
    sort(ps.begin() , ps.end());

} 

//=====================================

signed main()
{

    play();
    // freopen("some.in" , "r",stdin);
    // fast
    ll t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
}