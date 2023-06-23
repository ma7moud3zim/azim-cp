#include <bits/stdc++.h>
#include <ext/numeric>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "Yes" : "No") << nl;
using namespace std;
using namespace __gnu_cxx;
void play()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

#ifndef ONLINE_JUDGE
    cout<<"==========(input from file)=========="<<nl;
    freopen("input.txt", "r", stdin);
#endif
}
/*=====================================
 ⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⢸⡿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⢿⣧⠀⠀⠀⠀⠀
 ⢀⣀⣀⣀⣀⣸⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸⣿⣀⣀⣀⣀⠀
 ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇
 ⠀⠀⠀⠉⢙⣿⡿⠿⠿⠿⠿⠿⢿⣿⣿⣿⠿⠿⠿⠿⠿⢿⣿⣛⠉⠁⠀⠀
 ⠀⠀⠀⣰⡟⠉⢰⣶⣶⣶⣶⣶⣶⡶⢶⣶⣶⣶⣶⣶⣶⡆⠉⠻⣧⠀⠀⠀
 ⠀⠀⠀⢻⣧⡀⠈⣿⣿⣿⣿⣿⡿⠁⠈⢿⣿⣿⣿⣿⣿⠁⠀⣠⡿⠀⠀⠀
 ⠀⠀⠀⠀⠙⣿⡆⠈⠉⠉⠉⠉⠀⠀⠀⠀⠉⠉⠉⠉⠁⢰⣿⠋⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⣠⣶⣶⣶⣶⣶⣶⣄⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⠸⣷⡀⠀⠀⣿⠛⠉⠉⠉⠉⠛⣿⠀⠀⢀⣾⠇⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⠀⠘⢿⣦⡀⣿⣄⠀⣾⣷⠀⣠⣿⣀⣴⡟⠁⠀⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀
 ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
=====================================*/


struct P{
    int x,y;
};  

void run()
{
    ll n;
    cin>>n;
    // x,y lower left
    // x,y upper right

    pair<P,P> ans = {{INT_MAX,INT_MAX} , {INT_MIN,INT_MIN}};

    while(n--){
        char c;
        cin>>c;
        if(c=='c'){
            P circle;
            int r;
            cin>>circle.x>>circle.y>>r;
            
            ans.fs.x = min(ans.fs.x,circle.x-r);
            ans.fs.y = min(ans.fs.y,circle.y-r);

            ans.sc.x = max(ans.sc.x,circle.x+r);
            ans.sc.y = max(ans.sc.y,circle.y+r);
        }else if(c=='l'){
            P l1,l2;
            cin>>l1.x>>l1.y>>l2.x>>l2.y;
            ans.fs.x = min({ans.fs.x , l1.x,l2.x});
            ans.fs.y = min({ans.fs.y , l1.y,l2.y});            
            
            ans.sc.x = max({ans.sc.x , l1.x,l2.x});
            ans.sc.y = max({ans.sc.y , l1.y,l2.y});

        }else{
            P p;
            cin>>p.x>>p.y;
            ans.fs.x = min(ans.fs.x , p.x);
            ans.fs.y = min(ans.fs.y , p.y);            
            
            
            ans.sc.x = max(ans.sc.x , p.x);
            ans.sc.y = max(ans.sc.y , p.y);            
        }
    }
    cout<<ans.fs.x<<' '<<ans.fs.y<<' '<<ans.sc.x<<' '<<ans.sc.y<<nl;
}


//=====================================

signed main()
{
    play();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
}