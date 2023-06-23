int BIT[MAXN];
void update(int x, int val)
{
    ++x;
    while (x <= N)
        BIT[x] += val x += (x & -x);
    
}
int query(int x)
{
    ++x;
    int res = 0;
    while (x > 0)
    {
        res += BIT[x];
        x -= (x & -x);
    }
    return res;
}


vector<ll> randomArray(ll n){
    vector<ll> v(n);
    for(int i=0; i<n; i++){
        v[i] = rand()%20;
    }
    return v;
}