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
const ll mx = 1e5+5;
ll a[mx][3];
ll clc[mx][3];
ll n; 

ll calc(int d , ll tak){
	if(d == n) return 0;
	if(~clc[d][tak]) return clc[d][tak];
	
	if(tak == 0){
		clc[d][tak] = a[d][tak] + max(calc(d+1,1),calc(d+1,2));
		return clc[d][tak];
	}
	if(tak == 1){
		clc[d][tak] =  a[d][tak] + max(calc(d+1,0),calc(d+1,2));
		return clc[d][tak];
	}
		clc[d][tak] = a[d][tak] + max(calc(d+1,0),calc(d+1,1));
		return clc[d][tak];
}


void run(){
	
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}

	memset(clc, -1,sizeof clc);
	ll a1 = calc(0,0);
	memset(clc, -1,sizeof clc);
	ll a2 = calc(0,1);
	memset(clc, -1,sizeof clc);
	ll a3 = calc(0,2);

	cout<<max({a1,a2,a3});
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