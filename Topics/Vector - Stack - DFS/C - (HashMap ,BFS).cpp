#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define pii pair<int, int>
#define fs first
#define sec second
#define x fs
#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue
#define br break;
#define cntpop __builtin_popcount
using namespace std;
queue<pii>q;
map<pii,int>mp;
// directions 
int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1}

void run(){
    pr x;
    pr y;
    cin>>x.fs>>y.fs;
    cin>>x.sec>>y.sec;
    cin>>n;
    ll rw,fr,to;
    while(n--){
        cin>>rw>>fr>>to;
        for(int i=fr;i<=to;i++)mp[{rw,i}]=-1;
    }
    mp[{x.fs,y.fs}]=0,mp[{x.sec,y.sec}]=-1;
    q.push({x.fs,y.fs});
    while(q.size()){
        pr u=q.front();q.pop();

        for(int i=0;i<8;i++){
            pr v = {u.fs+dx[i],u.sec+dy[i]};
            if(mp[v]==-1) mp[v]=mp[u]+1,q.push(v);
        }
        
    }

    cout<<mp[{x.sec , y.sec}]<<nl;
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