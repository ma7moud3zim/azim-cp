#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================

const int N = 1e5+4;
int n, m, par[N], cnt[N];

void init(int n){
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);
}
int findParent(int u){
    if(u == par[u]) return u;
    return par[u] = findParent(par[u]);
}
bool join(int u, int v){
    u = findParent(u),v = findParent(v);
    if(u != v){
        if(cnt[u] > cnt[v])
            swap(u, v);
        par[u] = v;
        cnt[v] += cnt[u];
		return 1;
    }else return 0;
}

void run()
{
	ll n; 
	cin>>n;
	vector<pair<ll,ll>> cls;
	init(n+1);

	for(int i=0; i<n-1; i++){
		ll u,v;
		cin>>u>>v;
		if(!join(u,v)){
			cls.pb({u,v});
		}
	}
	set<ll> st;
	for(int i=1; i<=n; i++){
		st.insert(findParent(i));
	}
	cout<<cls.size()<<nl;
	int i=0;
	bool f=0;
	for(auto nd:st){
		if(!f){ f=1;continue;}
		cout<<cls[i].fs<<' '<<cls[i].sc<<' ';
		cout<<*st.begin()<<' '<<nd<<nl;
		i++;
	}


}

//====================
int main()
{
#ifndef ONLINE_JUDGE
	freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
	cin.tie(0)->sync_with_stdio(0);
#endif

	ll t = 1;
	// cin >> t;
	while (t--)
		run();
}
