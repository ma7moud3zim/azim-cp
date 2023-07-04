#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout<<#x<<": "<<x<<nl
using namespace std;
//============================
const int N = 1e5+4;
int dvs[N];
int tc;
void run(){
    int n;
    cin>>n;
    memset(dvs,0,sizeof dvs);
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        ll cr; 
        cin>>cr;
        for(ll j=1; (j*j)<=cr; j++){
            if(cr%j==0){
                dvs[j]++;
                if(dvs[j]==2) pq.push(j);
                if(j!=cr/j){
                    dvs[(cr/j)]++;
                    if(dvs[cr/j] == 2) 
                        pq.push(cr/j);
                }
            }
        }
    }

    n--;
    ll ans =0;
    while(pq.size() && n--){
        int val = pq.top();
        ans += val;
        dvs[val]-=2;
        if(dvs[val]<2) pq.pop();
    }

    cout<<"Case "<<++tc<<": "<<ans<<nl;
}
//============================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    freopen("dream.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0); 
#endif
    ll t=1;
    cin>>t;
    while(t--){
        run();
    }
}