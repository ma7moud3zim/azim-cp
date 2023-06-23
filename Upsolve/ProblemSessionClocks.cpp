#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string ops[] = {"ABDE",
                "ABC",
                "BCEF",
                "ADG",
                "BDEFH",
                "CFI",
                "DEGH",
                "GHI",
                "EFHI"};
                
vector<int>sol,cur;
const int mxx = 1<<18; 
int vis[mxx + 20],vid;

bool dfs(int s,int mx){
    if(!s) {
        sol=cur;
        return true;
    }
    if(!mx || vis[s]==vid) return false;
    vis[s]=vid;
    for (int i = 0; i <9 ; ++i) {
        int ns=s;
        for(auto c:ops[i]){
            c-='A';
            ns&=~(3<<(2*c));
            int x=(s>>(2*c))&3;
            x=++x&3;
            ns|=x<<(2*c);
        }
        cur.push_back(i+1);
       bool f=dfs(ns,mx-1);
       cur.pop_back();
       if(f)
            return true;

    }
    return false;
}
void solve(int s){
    for (int i = 0; ++vid,!dfs(s,i) ; ++i);
}
int main() {

#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int x,s=0;
    for (int i = 0; i <9 ; ++i) {
        cin>>x;
        s|=x<<(2*i);
    }
    solve(s);
    sort(sol.begin() , sol.end());

    for(auto &x: sol){
        cout<<x<<" \n"[&x==&sol.back()];
    }
}