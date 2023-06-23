#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
//=================================================
/* The idea between the solution is to ignore 
   unnecessary segments cuz we can say that 
   if you calculate the xor of this segment 
   "7 8 2 3 9" is the same for this segment 
   "7 8 2 3 9 1 4 5 6" and (from 1 to 6 elements answer the same)
*/
void run(){
    int n, ans = 0;
	cin >> n;
 
	stack<int> stk;
    int v;
	while(n--) {
		cin >> v;
        // stack always sorted asc
		while(!stk.empty()) {
			int x = stk.top();
            ans = max(ans,v^x);
			if (x > v) break;
            
            stk.pop();
		}
		stk.push(v);
	}
	
	cout << ans << endl;
}   



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