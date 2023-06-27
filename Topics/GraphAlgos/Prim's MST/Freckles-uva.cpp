#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================
#define Edge pair<double,pair<double,double>> 
#define w fs
#define To sc 

const double INF = INT_MAX;


ll n;
vector<pair<double,double>> a;

double adj(pair<double,double> &x , pair<double,double> &y){
    return sqrt((x.fs-y.fs)*(x.fs-y.fs) +(x.sc-y.sc)*(x.sc-y.sc));
}

void prim() {
    double total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n , {INF,{-1,-1}});
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }
        selected[v] = 1;
        total_weight += min_e[v].w;

        for (int to = 0; to < n; ++to) {
            if (adj(a[v],a[to]) < min_e[to].w)
                min_e[to] = make_pair(adj(a[v],a[to]), a[v]);

        }
    }

    cout<<fixed<<setprecision(2)<<total_weight << nl;
}

void run()
{
    cin>>n;
    a.clear();
    a.resize(n);
    for(int i=0; i<n; i++){
        cin>>a[i].fs>>a[i].sc;
    }
    prim();
}

//====================
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll t = 1;
    cin >> t;
    while (t--){
        run();
        if(t) cout<<nl;
    }
}#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================
#define Edge pair<double,pair<double,double>> 
#define w fs
#define To sc 

const double INF = INT_MAX;


ll n;
vector<pair<double,double>> a;

double adj(pair<double,double> &x , pair<double,double> &y){
    return sqrt((x.fs-y.fs)*(x.fs-y.fs) +(x.sc-y.sc)*(x.sc-y.sc));
}

void prim() {
    double total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n , {INF,{-1,-1}});
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }
        selected[v] = 1;
        total_weight += min_e[v].w;

        for (int to = 0; to < n; ++to) {
            if (adj(a[v],a[to]) < min_e[to].w)
                min_e[to] = make_pair(adj(a[v],a[to]), a[v]);

        }
    }

    cout<<fixed<<setprecision(2)<<total_weight << nl;
}

void run()
{
    cin>>n;
    a.clear();
    a.resize(n);
    for(int i=0; i<n; i++){
        cin>>a[i].fs>>a[i].sc;
    }
    prim();
}

//====================
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll t = 1;
    cin >> t;
    while (t--){
        run();
        if(t) cout<<nl;
    }
}