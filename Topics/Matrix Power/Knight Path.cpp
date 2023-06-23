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

typedef vector<vector<unsigned int>> matrix;
struct mul{
    int n;
    mul(int n):n(n){}

    matrix operator()(const matrix &a,const matrix & b){
        matrix ret(a.size(),vector<unsigned int>(b[0].size()));

        for (int i = 0; i <a.size() ; ++i) {
            for (int j = 0; j <b[0].size() ; ++j) {
                ret[i][j]=0;
                for (int k = 0; k <b.size() ; ++k) {
                    ret[i][j]+=(a[i][k]*1ll*b[k][j]);
                }
            }
        }
        return ret;
    }
};

matrix identity_element(const mul& m){
    matrix ret(m.n,vector<unsigned int>(m.n));
    for (int i = 0; i <m.n ; ++i)
        ret[i][i]=1;
    return ret;
}

bool inside(int row, int col) {
	return 0 <= min(row, col) && max(row, col) < 8;
}


void run(){
    int k;
	cin >> k;
	k++;
	matrix m;
    m.resize(65);
    for(int i=0; i<65; i++) m[i].resize(65);

	for(int row=0; row<8; row++) {
	    for(int col=0; col<8; col++) {
		    for(int dr : {-2,-1,1,2}) {
		        for(int dc : {-2,-1,1,2}) {
			        if(abs(dr) != abs(dc)) {
				        int new_row = row + dr;
					    int new_col = col + dc;
				        if(inside(new_row, new_col)) {
					        m[8*row+col][8*new_row+new_col] = 1;
					    }
				    }
			    }
		    }
	    }
    }

	for(int i = 0; i <= 64; i++) {
		m[i][64] = 1;
	}

    // we pass mul to override the orginal power function
    mul overMul(2);
    auto ret=power(m,k,overMul);
    cout<<ret[0][64]<<'\n';
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

