#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#define nl '\n'
#define ll long long 
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
//=================================================
const int N=1e5+3,M=2e5+3,MOD=1e4;
int mem[11][2][2][90][90],k;
string a,b;

int solve(int i,bool A,bool B,int r1,int r2){
    if(i==a.size()) return !r1 && !r2;

    int &ret=mem[i][A][B][r1][r2];
    if(~ret)
        return ret;

    ret=0;
    for (int d = A?a[i]-'0':0; d <=(B?b[i]-'0':9) ; ++d)
        ret+=solve(i+1 , A && (d==a[i]-'0'),B&& (d==b[i]-'0'),(r1*10+d)%k,(r2+d)%k);

    return ret;
}

void run(){
    memset(mem, -1, sizeof(mem));
    cin >> a >> b >> k;

    if (k > 89) cout << "0\n";
    else {
        a = string(b.size() - a.size(), '0') + a;
        cout << solve(0, 1, 1, 0, 0) << '\n';
    }
}


//=================================================
signed main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ll t=1 , c=0; 
    cin>>t;
    while(t--){
       cout << "Case " << ++c<< ": ";
       run();
    }
}