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
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
using namespace __gnu_cxx;
//=================================================
const ll N = 60005;
ll n;
pair<ld,ld> a[N];
ld md;


bool chk(){
    ld L = LLONG_MIN, R = LLONG_MAX;
    ld lft , rit;    

    for(int i=0; i<n; i++){
        lft = a[i].fs - (md*a[i].sc);
        rit = a[i].fs + (md*a[i].sc);

        L = max(L , lft);
        R = min(R , rit);
    }
    return (L <= R);
}

void run(){
    cin>>n;
    // اتأكد بعد كدا إنك واخد أم الانبوت صح
    for(int i=0; i<n; i++){
        cin>>a[i].fs;
    }
    for(int i=0; i<n; i++){
        cin>>a[i].sc;
    }

    ld l =0, r=1e11;

    while(r-l>1e-6){
        md = l + (r-l) /2;

        if(chk())   
            r = md;
        else
            l = md;
        
    }

    cout<<fixed<<setprecision(10)<<md<<nl;

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