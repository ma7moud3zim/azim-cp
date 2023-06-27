#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
//=================================================
ll n , m;
ll a[201],b[201];


bool val(int x){

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
        {    
            if((a[i]&b[j]|x) == x)break;
		    else if(j==m-1) return 0;
        }
	}

	return 1;
}

void run(){
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    
    ll ans = 511;

	for(int i=8;i>=0;--i) val(ans^(1<<i)) ? ans^=(1<<i):0;

    cout<<ans<<nl;   

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
