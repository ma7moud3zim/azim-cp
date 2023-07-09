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
const ll N = 1e6+7; 
const int mod = 1e9+7;
ll A[N],B[N];

void run(){
	A[1]=1,B[1]=1;
	/*
		A |_ _|
		B |_|_|
	*/

	for(int i=2;i<N; i++){
		A[i] = ((2*A[i-1])%mod+B[i-1])%mod;
		B[i] = (A[i-1] + (4*B[i-1])%mod)%mod;
	}	
}

/*

In Type A:
valid valid	 not   not  
 _ _   _ _   _ _   _ _
|_|_| |_ _|	|_| | | |_|  
|_ _| |_ _| |_ _| |_ _| 


In Type B:
valid valid valid valid
 _ _   _ _   _ _   _ _
|_|_| |_ _|	|_| | | |_|  
|_|_| |_|_| |_|_| |_|_| 

*/

//============================
int main()
{
#ifndef ONLINE_JUDGE
	freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
	cin.tie(0)->sync_with_stdio(0);
#endif
	ll t=1;
	cin>>t;
	run();
	while(t--){
		ll n;
		cin>>n;
		cout<<(A[n]+B[n])%mod<<nl;
	}
}