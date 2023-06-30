#include <bits/stdc++.h>
#include <unordered_set>
#define ll long long
#define ld long double
#define nl << '\n'
#define loop(n) for (long long i = 0; i < n; i++)
#define loop2(a, n) for (long long j = a; j < n; j++)
#define test \
  int t;     \
  cin >> t;  \
  while (t--)
#define yn cou t << (ok ? "YES" : "NO")nl;
#define pill pair<ll, ll>
#define pb push_back
#define fs first
#define sc second
#define nn \
  int n;   \
  cin >> n;
#define alpha cin.tie(0)->sync_with_stdio(0);
using namespace std;

int solve()
{
  ll n, k, x;
  cin >> n >> k >> x;
  if ((k == 2 && n % 2 == 1 && x == 1) ||( k == 1 && x == 1))
    cout << "NO\n";
  else if (k >=2 && n % 2 == 0&&x!=2)
  {
    cout << "yes\n";
    cout << n / 2 nl;
    loop(n / 2)cout << 2 << " ";
    cout nl;
  }
  else if (x != 1)
  {
    cout << "yes\n";
    cout << n nl;
    loop(n) cout << 1 << " ";
    cout nl;
  }
  else if (x == 1&&k>=3)
  {
    if (n == 3)
      cout << "yes\n"<< 1 nl << 3 nl;
    else
    {
      cout << "yes\n";
      ll sum = n - 3;
      cout << (sum / 2) + 1 nl;
      loop(sum / 2) cout << 2 << " ";
      cout << 3 nl;
    }
  }
  else cout<<"no\n";

  return 0;
}

int main()
{
  alpha  

    test{
      solve();
    }
}