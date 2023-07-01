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
const int N = 27;
int n, m, par[N], cnt[N];
vector<vector<ll>> gr;

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
    } return 0;
}

 bool isCyclic() {
        vector<int> inDegree(26, 0); 
        queue<int> q; 
        int visited = 0;
        for (int u = 0; u < 26; u++) {
            for (auto v : gr[u]) {
                inDegree[v]++;
            }
        }
        for (int u = 0; u < 26; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;
            for (auto v : gr[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited != 26; 
}

void run()
{
	ll n; cin>>n;
	string a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	set<ll> st;
	string ans = "";
	for(int i=0; i<26;i++) st.insert(i);
	init(27);
	gr.resize(26);

	for(int i=0; i<n-1; i++){
		bool f =0;
		for(int j=0;j<min(a[i].size(),a[i+1].size()); j++){
			ll u =a[i][j]-'a', v = a[i+1][j]-'a'; 
			if(u != v){
				f=1;
				gr[u].pb(v);

				if(join(u,v)){
					if(st.count(u)) st.erase(u),ans+=(u+'a');
					if(st.count(v)) st.erase(v),ans+=(v+'a');
				}else{
					cout<<"Impossible"<<nl;
					return;
				}
				break;
			}
		}
		if(!f){
			if(a[i].size()>a[i+1].size()){
				cout<<"Impossible"<<nl;
				return;
			}
		}
	}
	
	for(auto ch:ans) cout<<ch;
	for(auto ch:st) cout<<char(ch+'a');
	cout<<nl;
	
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