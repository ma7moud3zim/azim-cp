#include <bits/stdc++.h>
#define nl '\n'
#define fast cin.tie(0)->sync_with_stdio(0);
#define ll long long
#define int long long
#define ld long double
#define pill pair<ll, ll>
#define pb push_back
#define fs first
#define sc second
#define yn cout << (ok ? "YES" : "NO") << nl;
using namespace std;
void play()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
#ifndef ONLINE_JUDGE
    cout << "==========(input from file)==========" << nl;
    freopen("input.txt", "r", stdin);
#endif
}
ll tc;
//=====================================
char b[9][9];
bool kn[9][9] = {};
bool vl(int i,int j){
    
    if(i>=0 && j>=0 && j<8 && i<8 ){
        if(b[i][j] == '.' || b[i][j]=='K'){
            return true;
        }else{
            kn[i][j]=1;
            return false;
        }
    }else return false;
}

 
void run()
{
    memset(kn,0,sizeof(kn));
    pill pos;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>b[i][j];
            if(b[i][j]=='K') pos = {i,j};
        }
    }

    int dx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
    int dy[] = { 0,-1, 1, 0, 1, -1 , 1,-1};
 
   for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
        
        char cr = b[i][j];
        if(cr == 'P'){
            if(vl(i-1,j-1))
                kn[i-1][j-1] = 1;
            if(vl(i-1,j+1))
                kn[i-1][j+1] = 1;
        }

        if(cr == 'N'){
            if(vl(i-1,j-2))
            kn[i-1][j-2]=1;

            if(vl(i-2,j-1))
            kn[i-2][j-1]=1;
            
            if(vl(i-2,j+1))
            kn[i-2][j+1]=1;
            
            if(vl(i-1,j+2))
            kn[i-1][j+2]=1;
            
            if(vl(i+2,j-1))
            kn[i+2][j-1]=1;
            
            if(vl(i+1,j-2))
            kn[i+1][j-2]=1;
            
            if(vl(i+2,j+1))
            kn[i+2][j+1]=1;
            
            if(vl(i+1,j+2))
            kn[i+1][j+2]=1;
        }

        if(cr == 'R' || cr == 'Q'){
            for(int k=i+1; k<8;k++){
                if(vl(k,j))
                    kn[k][j] = 1; 
                else break;
            }
            for(int k=i-1; k>=0;k--){
                if(vl(k,j))
                    kn[k][j] = 1; 
                else break;
            }
            for(int k=j+1; k<8;k++){
                if(vl(i,k))
                    kn[i][k] = 1; 
                else break;
            }
 
            for(int k=j-1; k>=0;k--){
                if(vl(i,k))
                    kn[i][k] = 1; 
                else break;
            }
        }
 
        if(cr == 'B' || cr == 'Q'){
            for(int dr=4; dr<8; dr++){
                for(int u=i+(dx[dr]),v=j+dy[dr]; u<8 && u>=0 && v<8 && v>=0;){
                    if(vl(u,v)) kn[u][v] = 1;
                    else break;
                    
                    u += dx[dr];
                    v += dy[dr];
                }
            }
        }

        // if(cr == 'Q') kn[i][j] = 1;
    }
   }

   
    //    for(int i=0; i<8; i++){
    //     for(int j=0; j<8; j++){
    //         if(b[i][j]!='.' && !kn[i][j])
    //             cout<<b[i][j];
    //         else cout<<kn[i][j];
    //     }
    //     cout<<nl;
    // }


    ll u = pos.fs,v=pos.sc;
    for(int i=0; i<8; i++){
        ll cu = u + dx[i] , cv = v + dy[i];
        if(!(cu>=0 && cv>=0 && cu<8 && cv<8)) continue;

        if(!kn[cu][cv]){
            cout<<"Yes"<<nl;
            return;
        }
    }
    

    cout<<"No"<<nl;
}

//=====================================

signed main()
{

    // play();
    // freopen("some.in" , "r",stdin);
    fast
    ll t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
}