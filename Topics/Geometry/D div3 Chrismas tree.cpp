#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define ld double
#define double long double
#define pdd pair<double, double>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout<<#x<<": "<<x<<nl
using namespace std;
//============================
double h,b;

double polygonArea(double X[], double Y[], int n)
{
    double area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i; 
    }

    return abs(area / 2.0);
}

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);
 
    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);
 
    double determinant = a1*b2 - a2*b1;
 
    if (determinant == 0)
    {
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

double getDist(pdd a, pdd b){
	return sqrt((a.fs-b.fs)*(a.fs-b.fs) + (a.sc-b.sc)*(a.sc-b.sc));
}



void run(){
	ll n; cin>>n;
	cin>>b>>h;
	double a[n];
	for(int i=0; i<n;i++){
		cin>>a[i];
	}
	reverse(a,a+n);
	ld ans=0;
	ans+=((ld)h*(ld)b/2.0);

	for(int i=1; i<n; i++){
		// check intersection a[i] a[i-1]

		// the line of cur triangle
		pdd p1 = {0,a[i]+h},pp1={(b/2),a[i]};
		// base of last
		pdd p2 = {b/2,a[i-1]},pp2={-b/2,a[i-1]};
		
		pdd o = lineLineIntersection(p1,pp1,p2,pp2);
		// db(o.fs) , db(o.sc);

		double ab = getDist(p2,pp2);
		double ap = getDist(p2,o);
		double Pb = getDist(o,pp2);
		
		// there calc polygon
		if(ab == ap + Pb && o.fs>0 && o.sc>0){
			p1 = {0,a[i]+h},pp1={-(b/2),a[i]};

			pdd o2 = lineLineIntersection(p1,pp1,p2,pp2);
			p2 = {b/2,a[i]},pp2={-b/2,a[i]};
			double x[4] = {o2.fs,o.fs,p2.fs,pp2.fs}; 
			double y[4] = {o2.sc,o.sc,p2.sc,pp2.sc};
			
			// for(int k=0; k<4;k++) cout<<x[k]<<' ';
			// cout<<nl;
			// for(int k=0; k<4;k++) cout<<y[k]<<" ";
			// cout<<nl;

			double ar = polygonArea(x,y,4);
			
			ans+=ar;
		}else{
		// there not calc triangle area
			ans+=((ld)h*(ld)b/2.0);
		}
	}
	cout<<fixed<<setprecision(8);
	cout<<ans<<nl;

}
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
	while(t--){
		run();
	}
}