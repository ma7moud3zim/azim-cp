#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
#include<ext/numeric>
#define nl '\n'
#define ll long long 
#define ld long double
#define pill pair<ll,ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
using namespace __gnu_cxx;
void play(){
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
//=================================================
typedef vector<vector<int>> matrix;
const int MOD = 1000000007;

struct mul{
    int n;
    mul(int n):n(n){}

    matrix operator()(const matrix &a,const matrix & b){
        matrix ret(a.size(),vector<int>(b[0].size()));

        for (int i = 0; i <a.size() ; ++i) {
            for (int j = 0; j <b[0].size() ; ++j) {
                ret[i][j]=0;
                for (int k = 0; k <b.size() ; ++k) {

                    ret[i][j]+=(a[i][k]*1ll*b[k][j])%MOD;

                    if(ret[i][j]>=MOD)
                        ret[i][j]-=MOD;
                }
            }
        }
        return ret;
    }
};

matrix identity_element(const mul& m){
    matrix ret(m.n,vector<int>(m.n));
    for (int i = 0; i <m.n ; ++i)
        ret[i][i]=1;
    return ret;
}


void run(){
    ll n;
    cin>>n;
    matrix m={{19,  7},{6,20}},x={{1},{0}};
    mul mm(2);
    auto ret=mm(power(m,n,mm),x);
    cout<<ret[0][0]<<'\n';
}

//=================================================
signed main()
{
    play();
    ll t=1; 
    // cin>>t;
    while(t--){
        run();
    }
}
