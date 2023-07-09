#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout<<#x<<": "<<x<<nl
using namespace std;
//============================
// DP to optimize problem 
// You want to minimize the price 
// and maxmize the pages number
// A variation of knapsack
void run(){
    int n,x;
    cin>>n>>x;
    int m[n],p[n];
    for(int i=0; i<n;i++)
        cin>>m[i];
    for(int i=0; i<n; i++)
        cin>>p[i];
        
    int dp[x+1] ={};
    for(int i=0; i<n;i++){  
        for(int j=0; j<=x; j++){
            if(j+m[i]<=x)
                dp[j] = max(dp[j] , dp[j+m[i]] + p[i]);
        }
    }

    cout<<dp[x]<<nl;
}

void optmized_solution_RollBack_technique(){
    int n,x;
    cin>>n>>x;
    int prc[n],pgs[n];
    for(int i=0; i<n;i++)
        cin>>prc[i];
    for(int i=0; i<n; i++)
        cin>>pgs[i];
    
        int dp[2][x+1] ={};
        for(int i=0; i<n;i++){ 
            for(int j=0; j<=x; j++){
                dp[i&1][j] = dp[(i&1)==0][j];
                if(prc[i] <= j) 
                    dp[i&1][j] = max(dp[i&1][j], 
                    dp[(i&1)==0][j-prc[i]]+pgs[i]);
            }
        }  
    cout<<((n%2)? dp[0][x] : dp[1][x])<<nl;
}

void normal_iterative_solution(){
    int n,x;
    cin>>n>>x;
    int prc[n],pgs[n];
    for(int i=0; i<n;i++) cin>>prc[i];
    for(int i=0; i<n;i++) cin>>pgs[i];

    int dp[n+1][x+1] ={};
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            dp[i][j] = dp[i-1][j];
            if((j-prc[i-1]) >= 0){
                dp[i][j] = max(dp[i][j] , 
                    dp[i-1][j-prc[i-1]] + pgs[i-1]);
            }
        }
    }
    cout<<dp[n][x]<<nl;
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
        optmized_solution_RollBack_technique();
    }
}