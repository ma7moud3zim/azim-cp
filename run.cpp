#include <bits/stdc++.h>

using namespace std;

int N, M, K, S, T, dist[10009],
	nextT[10009], nextE[10009], neigRoot[10009],
	root[10009], x[50009], y[50009], z[50009], INF = 1e9;

int Nodes, fii[1000009][4];

bool computed[10009];

pair<int, int> elem[1000009];
vector<pair<int, int>> edge[10009], out[10009];

// Add graph edge
void add_edge(int x, int y) { 
    fii[x][++fii[x][0]] = y; 
}

int cloneNode(int x)
{
	elem[++Nodes] = elem[x], memcpy(fii[Nodes], fii[x], sizeof(fii[x]));
	return Nodes;
}

int Insert(int nod, pair<int, int> val)
{
	if (nod == 0)
	{
		elem[++Nodes] = val;
		return Nodes;
	}

	int pos, ans = cloneNode(nod);
	if (fii[ans][0] == 0)
		pos = fii[ans][0] = 1;

	else if (fii[ans][0] == 1)
		pos = fii[ans][0] = 2;
	else
		pos = 1 + (rand() & 1);
	
	if (elem[ans] < val)
		fii[ans][pos] = Insert(fii[nod][pos], val);
	else
		fii[ans][pos] = Insert(fii[nod][pos], elem[ans]), elem[ans] = val;
	return ans;
}

void doDijkstra()
{
	priority_queue<pair<int, int>> PQ;
	for (int i = 1; i <= N; i++)
		dist[i] = INF, nextE[i] = nextT[i] = -1;
	dist[T] = 0, PQ.push({0, T});
	while (!PQ.empty())
	{
		pair<int, int> curr = PQ.top();
		PQ.pop();
		if (dist[curr.second] != -curr.first)
			continue;
		for (auto it : edge[curr.second])
			if (dist[x[it.first]] > dist[curr.second] + it.second)
				dist[x[it.first]] = dist[curr.second] + 
					it.second, nextE[x[it.first]] = it.first, 
					PQ.push({-dist[x[it.first]], x[it.first]});
	}
	for (int i = 1; i <= N; i++)
		if (nextE[i] != -1)
			nextT[i] = y[nextE[i]];
}

void compute(int nod)
{
	if (computed[nod])
		return;
	computed[nod] = 1;
	if (nextT[nod] != -1)
		compute(nextT[nod]);
	if (out[nod].empty())
	{
		if (nextT[nod] != -1)
			root[nod] = root[nextT[nod]];
		else
			root[nod] = 0;
	}
	else
	{
		sort(out[nod].begin(), out[nod].end());
		for (int i = 0; i < out[nod].size(); i++)
		{
			elem[Nodes + i + 1] = out[nod][i];
			if (i + 1 < out[nod].size())
				fii[Nodes + i + 1][0] = 1, fii[Nodes + i + 1][1] = Nodes + i + 2;
		}
		neigRoot[nod] = Nodes + 1, Nodes += out[nod].size();
		root[nod] = Insert(root[nextT[nod]], {out[nod][0].first, -nod});
	}
}

priority_queue<pair<long long, int>> ansPQ;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>N>>M>>K;
	cin>>S>>T;

	for (int i = 1; i <= M; i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		edge[y[i]].push_back({i, z[i]});
	}

	doDijkstra();
	
	for (int i = 1; i <= M; i++)
	{
		z[i] += dist[y[i]] - dist[x[i]];
		if (nextE[x[i]] != i && dist[y[i]] < INF)
			out[x[i]].push_back({z[i], i});
	}

	for (int i = 1; i <= N; i++)
		compute(i);
	
	for (int i = 1; i <= Nodes; i++)
		if (elem[i].second < 0)
		{
			int tail = -elem[i].second;
			elem[i].second = out[tail][0].second;
			for (int j = 1; j <= fii[neigRoot[tail]][0]; j++)
				fii[i][++fii[i][0]] = fii[neigRoot[tail]][j];
		}
	
	if (dist[S] >= INF)
	{
		while (K--)
			cout<<"NO\n";
		return 0;
	}

	cout<<dist[S]<<'\n', K--;
	if (root[S] != 0)
		ansPQ.push({-(dist[S] + elem[root[S]].first), root[S]});
	while (!ansPQ.empty())
	{
		if (K == 0)
			break;
		pair<long long, int> curr = ansPQ.top();
		ansPQ.pop();
		long long ans = -curr.first;
		cout<<ans<<'\n', K--;
		
		for (int i = 1; i <= fii[curr.second][0]; i++)
			ansPQ.push({-(ans - elem[curr.second].first + 
				elem[fii[curr.second][i]].first), 
				fii[curr.second][i]});
		
		int node = y[elem[curr.second].second];
		if (root[node] != 0)
			ansPQ.push({-(ans + 
				elem[root[node]].first), root[node]});
	}

	while (K--)
		cout<<"NO\n";
}
