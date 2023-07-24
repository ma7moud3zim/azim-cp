#include <bits/stdc++.h>
// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout<<#x<<": "<<x<<nl
using namespace std;
//============================
ll pr[20];
ll n;

ll f(int &msk, ll &nm)
{
  ll cur = 1;
  for (int i = 0; i < n; i++)
  {
    if ((msk >> i) & 1)
    {
      cur = pr[i]*cur / __gcd(pr[i],cur);
    }
  }
  return nm / cur;
}

ll all(ll &nm)
{
  ll ret = 0;
  int msk = 1;
  int up = 1 << n;
  while (msk < up)
  {
    ret += f(msk, nm) * (-1 + 2 * (__builtin_popcount(msk) % 2));
    msk++;
  }
  return ret;
}

void run()
{
  ll x;
  cin >> x >> n;
  map<ll, ll> vis;
  for (int i = 0; i < n; i++)
    cin >> pr[i];
  
  cout<<x-all(x)<<nl;
}
//============================
int main()
{
  // freopen("/input.txt", "r", stdin);
  cin.tie(0)->sync_with_stdio(0);
 run();
}