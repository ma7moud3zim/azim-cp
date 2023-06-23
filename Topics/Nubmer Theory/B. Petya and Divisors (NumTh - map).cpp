#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#include<ext/numeric>
#define nl '\n'
#define ll long long 
#define ld long double
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
using namespace __gnu_cxx;

//=================================================

 void run(){
   ll n; cin>>n;
   
   ll tm,y;
   map<ll,ll> apr;
   
   for(int i=1; i<=n; i++){
        cin>>tm>>y;
        ll ans = 0;
        for(int j=1; j*j<=tm; j++){
            if(tm%j==0){
                if(!(apr.count(j) && apr[j] >= i-y)) ans++;
                apr[j] = i;
                if(tm/j != j){
                    if(!(apr.count(tm/j) && apr[tm/j] >= i-y)) ans++;

                    apr[tm/j] = i;
                }
            }
        }
        cout<<ans<<nl;
   }
    
}

void problem_L_samaraa_Gym(){
    int n;
    cin>>n;

    map<int,int> mp;
    vector<int> d;
    
    for(int i =1; i*i <= n; i++){ 
        if(n%i == 0) {
    	    d.pb(i);
    	    if(n/i != i) d.pb(n/i);
        }
    }

    sort(d.begin(),d.end());
 
	for(int i=0; i<d.size(); i++){
		int pv =d[i]/2 +1;

		for(int i =2; i*i <= d[i]; i++) 
			if(d[i]%i == 0) 
                pv = min(pv,mp[i]*mp[d[i]/i]);
                
		mp[d[i]] = pv;
    }

	cout << mp[n] << "\n";

}

//=================================================
signed main()
{
    ll t=1; 
    // cin>>t;
    while(t--){
        run();
    }
}