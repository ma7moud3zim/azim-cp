#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
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
vector<ll> ans;

bool isCyclic(){
	vector<int> inDegree(26, 0);
	queue<int> q;
	int vis = 0;
	for (int u = 0; u < 26; u++)
		for (auto v : gr[u])
			inDegree[v]++;
	for (int u = 0; u < 26; u++)
		if (inDegree[u] == 0){
			q.push(u);
			ans.push_back(u);
		}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis++;
		for (auto v : gr[u])
		{
			inDegree[v]--;
			if (!inDegree[v]){
				q.push(v);
				ans.push_back(v);
			}
		}
	}
	return vis != 26;
}

void run()
{
	ll n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	gr.resize(26);
	for (int i = 0; i < n - 1; i++)
	{
		ll sz = min(a[i].size(), a[i + 1].size());
		bool b = 0;
		for (int j = 0; j < sz; j++)
		{
			if (a[i][j] != a[i + 1][j])
			{
				b = 1;
				gr[a[i][j] - 'a'].pb(a[i+1][j] - 'a');
				break;
			}
		}

		if (!b)
		{
			if (a[i].size() > a[i + 1].size())
				return cout << "Impossible" << nl, void();
		}
	}
	if(isCyclic()){
		cout << "Impossible" << nl;
	}else{
		for(auto i:ans)
			cout<<char(i+'a');
		cout<<nl;
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
	ll t = 1;
	// cin>>t;
	while (t--)
	{
		run();
	}
}