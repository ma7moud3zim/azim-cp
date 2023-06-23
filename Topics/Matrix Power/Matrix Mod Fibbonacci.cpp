
#include<ext/numeric>
using namespace __gnu_cxx;
typedef vector<vector<int>> matrix;
typedef long long ll;
const int N=2e3+2,M=1e5+3;
int MOD;
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
int main() {
    int n;
    while(cin>>n>>MOD){
        MOD=1<<MOD;
        matrix m={{0,1},{1,1}},x={{0},{1}};
        mul mm(2);
        auto ret=mm(power(m,n,mm),x);
        cout<<ret[0][0]<<'\n';
    }
}