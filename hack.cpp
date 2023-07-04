#include <bits/stdc++.h>
#define nl '\n'
#define ll long long
#define ld long double
#define pill pair<ll, ll>
#define fs first
#define sec second
#define x fs
#define sz(s) (int) (s.size())

#define y sec
#define yn cout << (ok ? "YES" : "NO") << nl;
#define pb push_back
#define cont continue;
#define loop(x,n) for(int x = 0; x < n; x++)
#define br break;
#define cntpop __builtin_popcount
using namespace std;
const int ch_MAX = 8;

string RandomString(int ch)
{
    char alpha[ch_MAX] = { 'm' , 'e', 'o' , 'w' , 'M' , 'E' , 'O' , 'W'};
    string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_MAX];
    return result;
}

string randString(int n)
{
  string res = "";
  for(int i=0; i<n; i++){
    res += (char(rand()%26 + 'a'));
  }
  return res;
}

bool solve1(string str){
    ll n = str.size();
    map<char, int> mp;
    vector<char> dis;
    set<char>st;

    for (int i = 0; i < n; ++i) {
        str[i] = char(tolower(str[i]));
        st.insert(str[i]);
    }
    if(st.size()>4){
        return 0;
    }
    for (auto &ch: str) {
        if (!mp[ch])
            dis.push_back(ch);
        else{
            if(ch != dis[dis.size() - 1]){
                return 0;
            }
        }
        mp[ch]++;
    }
 
    if (dis.size() == 4) {
        if (dis[0] == 'm' and dis[1] == 'e' and dis[2] == 'o' and dis[3] == 'w'){
          return 1;
        }
        else{
          return 0;
        }
    } else {
      return 0;
    }
}


string meow ="meow";
bool solve2(string str){
  
        ll n; n= str.size();
       bool ok = true;
       if(str.size() < 4) ok = false;
        int j = 0;
       for(int i=0; i<n;){
        
         if(j<4 && tolower(str[i]) == meow[j]){
            while(i<n && tolower(str[i]) == meow[j]) i++;
            j++;
         }
         else{
            ok = false;
            break;
         }
       }
       if(j != 4) ok = false;

      return ok;
}

int main(){
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
    
#ifndef ONLINE_JUDGE
    freopen("file.txt", "r", stdin);
#endif
  


}