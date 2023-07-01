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

ll lst_ans;

void run()
{ 
    ll n;
    n = (tc+2);
    tc+=2;
    cin>>n;
    ll m = 1e9+7;
    ll nn = n;
    if(n%2){
       n/=2;
       ll ans = n*(n+1) *2; 
       cout<<ans<<' ';
    }else{
       ll ans= (n/2 * (2+n-(n%2))) /2;
       ans*=2;
       cout<<ans<<' ';
    }

    ll ans = 0;
    for(ll i=1, j=n; i<j;i++,j--){
        ans = (ans + (((j-i)*nn)%m) )%m;
        nn--;
        ans = (ans + (((j-i)*nn)%m) )%m;
        nn--;
    }
    cout<<ans<<nl;
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