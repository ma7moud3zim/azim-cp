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
int mod=1e9+7; 
string a,b;
int n,m,d;
int mem[2003][2003][2][2];
int MOD = 1e9+7;

int calc(int i,int rem,bool pvA,bool pvB){
    if(i==n)return !rem;

    int &ret = mem[i][rem][pvA][pvB];
    if(~ret)return ret;
    
    ret=0;

    for(int j=(!i);j<=9;++j){
        if( (i&1) && j!=d || (!(i&1)&&j==d) ) continue;

        if((!pvA && j >=a[i]-'0')||pvA){
            if((!pvB && j <=b[i]-'0')||pvB){
                ret=(ret+calc(i+1,(rem*10+j)%m , pvA||(j>a[i]-'0'),pvB||(j<b[i]-'0')) ) % MOD;
            }
        }
    }
    return ret;
}

void run(){
    cin >> m >> d;
    cin >> a >> b;
    n=a.size();

    memset(mem,-1,sizeof mem);

    cout<<calc(0,0,0,0)<<endl;
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