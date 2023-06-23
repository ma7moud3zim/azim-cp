#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 1000005;
pair<int, int> p[MAX];
int par[MAX], asz[MAX], ans[MAX];
bool mark[MAX];
int find(int v)
{
	return (par[v] == v ? v : par[v] = find(par[v]));
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	par[u] = v;
	asz[v] += asz[u];
}
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < MAX; i++)
	{
		par[i] = i;
		asz[i] = 1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p, p + n, greater<pair<int, int> >());
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		int pos = p[i].second;
		int val = p[i].first;
		mark[pos] = true;
		if (pos && mark[pos - 1])
			merge(pos, pos - 1);
		if (pos < n - 1 && mark[pos + 1])
			merge(pos, pos + 1);
		int sz = asz[find(pos)];
		while (cur <= sz)
			ans[cur++] = val;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
