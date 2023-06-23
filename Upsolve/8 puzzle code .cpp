// temp code 

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
// directions 
int dx[]={-1,-1,-1,0,1,1,1,0},
    dy[]={-1,0,1,1,1,0,-1,-1};
typedef vector<vector<int>> mtrx;

const int N=2e3+3,MOD=1e4;

int encode(const mtrx &m){
    int ret = 0;
    for(auto &row:m){
        for(auto &cell:row){
            ret *=10;
            ret +=cell;
        }
    }
    return ret;
}

mtrx decode(int nm){
    mtrx ret(3,vector<int>(3));

    for(int i=2; i>=0;i--){
        for(int j=2; j>=0;j--){
            ret[i][j] = nm%10;
            nm/=10;
        }
    }
    return ret;
}

pii find0(const mtrx &m){

    for(int i=2; i>=0;i--){
        for(int j=2; j>=0;j--){
           if(!m[i][j]) return {i,j};
        }
    }
    return {-1,-1};
}

bool valid(int i,int j){
    return i>=0 && j>=0 && i<3 && j<3;
}
vector<int> get_neigh(int x){
    auto m = decode(x);

    int i,j;
    pii tm = find0(m);
    i = tm.fs;
    j = tm.sec;

    int di=0,dj=-1;
    vector<int> ret;
    for(int k=0; k<4; ++k){
        int ni = i+di , nj = j+dj;
        cout<<i<<' '<<j<<nl;
        cout<<di<<' '<<dj<<nl;
        cout<<ni<<' '<<nj<<nl;
        cout<<valid(ni,nj)<<nl;
        cout<<"============="<<nl;

        if(valid(ni,nj)){
            swap(m[i][j],m[ni][nj]);
            ret.pb(encode(m));
            swap(m[i][j],m[ni][nj]);
        }
        swap(di,dj);
        if(k == 1) dj = 1;
    }
    return ret;
}

unordered_map<int,int> mem;
void bfs(){
    queue<int> q;
    int g = 123456780,s;
    q.push(g);
    mem[g] = 0;
    
    for(int stp = 1; q.size(); ++stp){ 
        cout<<"Steps "<< stp<<nl;
        while(q.size()){
            for(auto v:get_neigh(q.front())){
                if(!mem.emplace(v,stp).sec)cont;
                q.push(v);
                // cout<<q.front()<<nl;
            }
            q.pop();
        }
    }
}



int cm = 0;
void run(){
    mtrx mt(3,vector<int>(3));

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cin>>mt[i][j];
    //     }
    // }

    int val = encode(mt);
    
    // cout<<val<<nl;
    cout<<"Case "<< ++cm<<": ";
    if(mem.count(val)) cout<<mem[val]<<nl;
    else cout<<"impossible"<<nl;
}

signed main()
{

#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    bfs();
    for(auto it:mem){
        cout<<it.fs<<' '<<it.sec<<nl;
    }
    ll t=1; 
    cin>>t;
    while(t--){
        run();
    }
}