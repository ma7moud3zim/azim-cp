#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) //cout<<#x<<": "<<x<<nl
using namespace std;
//============================
ll pr[11];
ll n;

ll f(int &msk, ll &nm){
  ll cur = 1;
  for(int i=0; i<n; i++){
    if((msk>>i)&1){
      cur*=pr[i];
    }
  }
  return nm/cur;
}

ll all(ll &nm){
  ll ret = 0;
  int msk = 1;
  int up = 1<<n;
  while(msk<up){
    ret += f(msk,nm) * (-1 + 2 * (__builtin_popcount(msk)%2));
    msk++;
  }
  return ret;
}

void run(){
  ll q;
  cin>>n>>q;
  for(int i=0; i<n; i++)
    cin>>pr[i];
  ll l,r;
  while(q--){
    cin>>l>>r;
    l--;
    // print all(r)-all(l-1)
    cout<<all(r)- all(l)<<nl;
    db(all(l));
    db(all(r));
  }
  

}
//============================
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
  cin.tie(0)->sync_with_stdio(0);
#endif
  ll t=1;
  // cin>>t;
  while(t--){
    run();
  }
}