#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================
ll n;
const ll mx = 3001;
double a[mx];
double mem[mx][mx];

double clc(int cur , ll t){
    double &ret = mem[cur][t];
    if(ret != -1) return ret; 

    
    if(cur == n){
        if( n-t > t){
            return ret = 1; 
        }
        return ret = 0;
    }
    double prc = a[cur];

    return ret = prc*clc(cur+1,t) + (1-prc)*clc(cur+1 , t+1);

}


void run(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<mx; i++)
        for(int j=0; j<mx; j++)
             mem[i][j] = -1;   

    cout<<fixed<< setprecision(10)<<clc(0,0)<<nl;
}


//=================================================
signed main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ll t=1; 
    // cin>>t;
    while(t--){
       run();
    }
}