#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimization("Ofast")
#define ll long long
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(x) cout << #x << ": \"" << x << '\"' << nl
using namespace std;
//====================


vector<int> constructLPS(vector<int>& pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

int countOccurrences(vector<int>& largerArray,
            vector<int>& smallerArray) {
    int n = largerArray.size();
    int m = smallerArray.size();

    vector<int> lps = constructLPS(smallerArray);
    
    int i = 0, j = 0;      
    int count = 0;
    
    while (i < n) {
        if (largerArray[i] == smallerArray[j]) {
            i++;
            j++;
            
            if (j == m) {
                count++;
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return count;
}

void run()
{
    ll m,n;
    cin>>m>>n;
    ll a[m],b[n];
    vector<int> ad(m-1),bd(n-1);
    if(m==1){
        cout<<n<<nl;
        return;
    }
    
    for(int i=0; i<m; i++){
        cin>>a[i];
        if(i) ad[i-1] = a[i] - a[i-1];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        if(i) bd[i-1] = b[i] - b[i-1];
    }

    cout<<countOccurrences(bd,ad)<<nl;
}

//====================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/input.txt", "r", stdin);
#endif
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif

    ll t = 1;
    // cin >> t;
    while (t--)
        run();
}