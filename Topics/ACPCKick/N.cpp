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


const ll N = 1e7+7;
ll spf[N];
vector<ll> pr;

void spfseive()
{
    for (ll i = 1; i < N; ++i)
        spf[i] = i;

    for (ll i = 2; i < N; ++i)
        if (spf[i] == i){
            pr.pb(i);
            for (ll j = i * i; j < N; j += i)
                spf[j] = min(i, spf[j]);
        }
    
    spf[1] = 1;
}

ll gpf(int n){
    if(spf[n] == n) return n;
    ll rt = INT_MIN;
    for(ll i=2; i*i<=n; i++){
        while(n%i==0) n/=i , rt = max(rt,i);

    }
    rt = max(rt,n);
    return rt;
}

void run()
{
    spfseive();
    
    ll n,d;
    cin>>n>>d;
    ll a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll r = 0 ,b = 0;
    
    for(int i=0;i<d;i++){
       if(a[i%n]<=1){
            if(b>r) cout<<"B"<<nl;
            else cout<<"R"<<nl;
    //    cout<<r<<' '<<b<<nl;
            continue;
       }

       ll cur = gpf(a[i%n]);
    //    cout<<a[i%n]<<' '<<cur<<nl;
       a[i%n] /= cur;
       ll ix = lower_bound(pr.begin() , pr.end(),cur) - pr.begin();
       if((ix+1)%2) r+=cur; 
       else b+=cur;

       if(b>r) cout<<"B"<<nl;
       else cout<<"R"<<nl;
    //    cout<<r<<' '<<b<<nl;
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