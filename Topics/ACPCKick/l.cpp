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
    ll n; cin>>n;
    vector<ll> od,ev;
    ll tm;
    for(int i=0; i<n; i++){
        cin>>tm;
        if(tm%2) od.pb(tm);
        else ev.pb(tm);
    }
    
    ll ods=od.size() , evs = ev.size();
    if(min(ods,evs)%2 ==0){
        cout<<"Even"<<nl;
    }else cout<<"Odd"<<nl;

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