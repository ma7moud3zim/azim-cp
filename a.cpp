#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": " << x << nl
using namespace std;
//============================
vector<vector<ll>> gr;
vector<ll> in;
ll n;
bool isCyclic(){
	queue<int> q;
	int vis = 0;
	for (int u = 0; u < n; u++)
		if (!in[u]){
			q.push(u);
		}
		
	while (q.size())
	{
		int u = q.front();
		q.pop();
		vis++;
		for (auto v : gr[u]){
			in[v]--;
			if (!in[v]){
				q.push(v);
			}
		}
	}

	return vis != n;
}

void run(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	string s;
	cin>>s;
	vector<pill> m,e,x;

	for(int i=0; i<n;i++){
		if(s[i] == 'M') m.pb({i,a[i]});
		if(s[i] == 'E') e.pb({i,a[i]});
		if(s[i] == 'X') x.pb({i,a[i]});
	}
	fo



}

//============================
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	ll t = 1;
	// cin>>t;
	while (t--)
	{
		run();
	}
}