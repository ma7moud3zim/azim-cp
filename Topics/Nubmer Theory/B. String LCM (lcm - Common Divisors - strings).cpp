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
void play(){
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
//=================================================

 
void run(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size() < s2.size()) swap(s1,s2);
    ll sz1=s1.size() ,sz2 = s2.size();
    set<ll> dv;
    for(int i=1;i*i<=sz1;i++){
        if(sz1%i==0){
            dv.insert(i) , dv.insert(sz1/i);
        }
    }
    vector<ll> cmnDv;
    for(int i=1;i*i<=sz2;i++){
        if(sz2%i==0){
            if(dv.count(i))cmnDv.pb(i);
            if(dv.count(sz2/i))cmnDv.pb(sz2/i);
        }
    }


    for(auto d:cmnDv){
        string cur ="";
        for(int i=0; i<d; i++){
            cur+=s1[i];
        }
        bool f = true;
        for(int i=0, j=0; i<sz1; i++){
            if(s1[i] == cur[j]){
                j++;
                if(j==cur.size()) j=0;
            }else{
                f= false;
                break;
            }
        }
        if(!f) continue;
        for(int i=0, j=0; i<sz2; i++){
            if(s2[i] == cur[j]){
                j++;
                if(j==cur.size()) j=0;
            }else{
                f= false;
                break;
            }
        }
        if(!f) continue;
        ll cr = sz1/gcd(sz1,sz2)*sz2;
        cr /= cur.size();
        for(int i=0; i<cr;i++){
            cout<<cur;
        }
        cout<<nl;
        return;
    }
    cout<<-1<<nl;
    
}

//=================================================
signed main()
{
    play();
    ll t=1; 
    cin>>t;
    while(t--){
        run();
    }
}