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
    ll n,k; cin>>n>>k;
    map<ll,ll> mp;
    ll tm;
    for(int i=0; i<n; i++) cin>>tm,mp[tm]++;
    vector<ll> v;
    for(auto [nm,fr]:mp){
        v.pb(fr);
    }

    sort(v.begin() , v.end());
    ll ans = mp.size();
    for(int i=0;i<v.size();i++){
        if(k>v[i]){
            k-=v[i];
            ans--;
        }else{
            if(v[i] == k) ans--;
            break;
        }
    }
    cout<<ans<<nl;
    
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