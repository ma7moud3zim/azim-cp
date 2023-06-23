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
const ll M =1e9+7;
ll n , m;
string d2[1001];

void run(){
	cin>>n>>m;
	for(int i=0; i<n;i++){
		cin>>d2[i];
	}
	ll ans[n][m] ={};
	memset(ans,0,sizeof ans);
	ans[0][0]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(d2[i][j] == '#' || (!i&&!j)) continue;

			if(i == 0) ans[i][j] = ans[i][j-1];
			else if(j == 0) ans[i][j] = ans[i-1][j];
			else{
				ans[i][j] = (ans[i][j]%M + ans[i-1][j]%M + ans[i][j-1]%M)%M;
			}
		}
	}
	cout<<ans[n-1][m-1]<<nl;
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