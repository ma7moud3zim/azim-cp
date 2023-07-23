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

/*
# Revise the next stuff in whole code.
1- Input is taken in the right way and input from file.
2- Ouput format is as wanted.
3- There are no OutOfBounds and all arrays-values are no garbage. 
4- memset and initializes.
5- Constraints and Overflow check DT and check if input is negative.
6- Every Condition in the Code include maximizing and minimizing.
7- Samble TestCases and try the smallest & biggest cases. 
*/

void run(){
  ll a[12];
  for(int i=0;i<12;i++){
    cin>>a[i];
  }
  
  if(is_sorted(a,a+4)){
    cout<<"yes"<<nl;
  }else {
    cout<<"no"<<nl;
  }
}
//============================
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
  cin.tie(0)->sync_with_stdio(0);
  freopen("hello.in", "r", stdin);
#endif
  ll t=1;
  cin>>t;
  while(t--){
    run();
  }
}