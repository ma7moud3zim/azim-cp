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


void run(){
  ll n ,k;
  cin>>n>>k;
  ll arr[n];
  bool ls = true;
  for(int i=0; i<n; i++){
    cin>>arr[i];
    ls &= (arr[i]<=k);
  }

  if(ls){
    cout<<"YES"<<nl;
    return;
  }

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(arr[i] + arr[j] <= k){
        cout<<"YES"<<nl;
        return;
      }
    }
  }  
  cout<<"NO"<<nl;

}

signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("file.txt", "r", stdin);
#endif
 ll t = 1;
 cin>>t;
 while(t--){
    run();
 }
    
}