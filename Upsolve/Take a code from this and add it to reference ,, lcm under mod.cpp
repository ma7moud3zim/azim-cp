#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define ll long long
#define mod 1000000007

int sp[N]; 

void generateSmallestPrime(){ 
	sp[0] = 1 , sp[1] = 1; 
	for(int i=2;i<N;i++){
		if(sp[i]) continue; 
		for(int j=i; j<N; j+=i){
			if(sp[j]) continue;
			sp[j] = i;
		}
	}
}

ll power(ll x, ll y){
    ll res = 1; 
    while(y){
        if(y&1) res = (res * x)%mod;
        y >>= 1 , x = (x*x)%mod;
    }
    return res;
}	

ll lcmWithModulo(vector<ll>&arr){
	unordered_map<ll, ll> primeMax;
	for(ll x: arr){
		while(x>1){ 
			ll sml_fctr = sp[x];
			ll count = 0;
			while(x % sml_fctr == 0) {
				x = x / sml_fctr;
				count++;
			}
			primeMax[sml_fctr] = 
			max(count, primeMax[sml_fctr]);
		}
	}
	ll res = 1; 
	for(auto &[fs,sc]: primeMax)
		res = 
		(res * powMod(fs, sc)) % mod;
	return res;
}


int main() {
	generateSmallestPrime();
	
	vector<int> arr = {13, 412, 56, 70, 333};
	cout << lcmWithModulo(arr) << endl;
	return 0;
}