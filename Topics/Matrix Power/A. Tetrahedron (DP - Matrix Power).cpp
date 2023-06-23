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
const int MOD = 1e9+7;
void Normal_dp_solution(){
    ll n;
    cin >> n;
    ll dp[n+5][2];
    dp[0][1] = 1;
    // This is linear dp O(n) solution
    for (int i = 1; i <= n;i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]*2 % MOD) %MOD;

        dp[i][1] = (dp[i - 1][0]  * 3)%MOD;
    }

    cout<<dp[n][1]<<nl;
}

typedef vector<vector<int>> matrix;


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

    matrix m;
    m.resize(4);
    for(int i= 0 ; i< 4; i++)
        m[i].resize (4);
 
    for(int i= 0 ; i< 4; i++)
    for(int j= 0 ; j< 4; j++)
        m[i][j] = (i == j? 0: 1);

    mul mm(2);
    auto ret=power(m,n,mm);
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

