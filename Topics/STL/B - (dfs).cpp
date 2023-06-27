#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define fs first
#define sec second
#define x fs
#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue;
#define br break;
#define cntpop __builtin_popcount
using namespace std;
const int mx = 501;
ll n,m,k;
char d2[mx][mx];
map<pill,bool> vis;

ll ans = 0;
ll al;
void dfs(pill cur){
    if(vis[cur] || cur.fs <0 || cur.fs >= n || 
    cur.sec < 0 || cur.sec >= m || d2[cur.fs][cur.sec] == '#') return;

    if(al == 0) return;

    vis[cur] = true;
    if(al <= k){
        d2[cur.fs][cur.sec] = 'X';
    }

    // cout<<cur.fs<<' '<<cur.sec<<' '<<al<<nl;
    al--;
    dfs({cur.fs+1,cur.sec});
    dfs({cur.fs-1,cur.sec});
    dfs({cur.fs,cur.sec+1});
    dfs({cur.fs,cur.sec-1});

}

signed main()
{


#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin>>n>>m>>k;
    pill fsp = {-1,-1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>d2[i][j];
            if(d2[i][j] == '.' && fsp.fs == -1){
                fsp = {i,j};
            }
            al += (d2[i][j]=='.'); 
        }
    }

    dfs(fsp);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){    
            cout<<d2[i][j];
        }
        cout<<nl;
    }
}