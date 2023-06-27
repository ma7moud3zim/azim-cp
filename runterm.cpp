#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================

void run()
{
    ll n;
    cin>>n;
    ll a[n+1][n+1];
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
        cin>>a[i][j];

    ll ans[n+1]={};
    for(int i=1; i<=n; i++)
    for(int j=i+1; j<=n; j++)
    {
        if(i==j) continue;
        ans[i] |= a[i][j];
        ans[j] |= a[i][j];
    }
    
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<' ';
    }
    cout<<nl;
}

//====================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

    ll t = 1;
    // cin >> t;
    while (t--)
        run();
}