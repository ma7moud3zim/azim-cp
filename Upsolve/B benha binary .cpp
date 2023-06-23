// B Exam problem of contest Benha - binary search
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define fs first
#define sec second
#define x fs
#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue;
#define br break;
#define cntpop __builtin_popcount
using namespace std;
vector<pill> ned,fre;

bool ch(ll mid){
    int cur=0,j=0;
    vector<pill> nedt=ned,fret=fre;

    while(cur<nedt.size() && j<fret.size()){

        // cout<<"====current mid=== "<<mid<<nl;
        // cout<<nedt[i].fs<<' '<<fret[j].fs<<nl;
        // cout<<nedt[i].sec<<' '<<fret[j].sec<<nl;
        // cout<<i<<' '<<j<<nl;
        if(nedt[cur].sec-fret[j].sec > mid){
            j++;
            cont;
        }
        
        if(fret[j].sec-nedt[cur].sec > mid){
            return 0;
        }

        if(fret[j].fs > nedt[cur].fs){
            fret[j].fs -= nedt[cur].fs;
            cur++;
        }else if(fret[j].fs < nedt[cur].fs){
            nedt[cur].fs -= fret[j].fs;
            j++;
        }else{
            cur++ , j++;
        }
    }

    return (cur==nedt.size());
}

void sol() {
    ll n;
    cin>>n;
    ll a[n],b[n];

    for(int i=0;i<n; i++)
        cin>>a[i];
    for(int i=0;i<n; i++)
        cin>>b[i];

     for(int i=0;i<n; i++){

        if(a[i]-b[i] > 0){
            ned.pb({a[i]-b[i] , i});
        }
        else if(a[i]-b[i] < 0){
            fre.pb({b[i]-a[i] , i});
        }

    }

    ll ans = -1;
    ll l = 0 , r = n-1;
    ll mid;
    while(l<=r){
        mid = (l+r)/2;

        if(ch(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<nl;
    
}

signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("file.txt", "r", stdin);
#endif
    ll t =1 ;
    //cin>>t;
    sol();
}