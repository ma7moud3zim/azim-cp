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
    ll a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    ll curod = -1;
    ll ans=0;
    ll l =0;
    for(int i=0; i<n; i++){
        if(a[i]%2){
            l = curod+1;
            curod = i;
        }
        ans =max(ans , i-l+1);
    }

    if(curod == -1) cout<<-1<<nl;
    else cout<<ans<<nl;
    
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