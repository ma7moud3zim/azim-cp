#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout<<#x<<": "<<x<<nl
using namespace std;
//============================

void run(){
    int n;
    cin>>n;
    int dp[n+1];
    for(int i=0; i<=n; i++)
        dp[i]=INT_MAX;
        
    dp[0] = 0;
    for(int i=0; i<=n; i++){
        string cur = to_string(i);
        for(auto c:cur){
            dp[i] = min(dp[i] , dp[i-c+'0']+1);
        }
    }
    cout<<dp[n]<<nl;
}
//============================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
    ll t=1;
    // cin>>t;
    while(t--){
        run();
    }
}