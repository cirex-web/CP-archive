
#include <bits/stdc++.h>

using ll = long long;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (a); i>=(b); i--)
#define endl '\n'
#define sz(a) (int(a.size()))
using namespace std;
const ll MOD = 1e9+7;

ll powf(ll n, ll pow){
    if(pow==0)return 1;
    ll res = pow%2?n:1;
    ll temp = powf(n,pow/2);
    return res*temp%MOD*temp%MOD;
}
int main() {
    int N; cin>>N;
    ll ans = 1;
    int pA = 1;
    vector<ll> fac(1e6),invFac(1e6);
    fac[0] = 1;

    FOR(i,1,sz(fac))fac[i] = fac[i-1]*i%MOD;
    invFac[sz(fac)-1] = powf(fac.back(),MOD-2);
    ROF(i,sz(invFac)-2,0)invFac[i] = invFac[i+1]*(i+1)%MOD;


    FR(i,N){
        int a; cin>>a;
        assert(a%2==0);
        a/=2;
        int newA = a;
        if(a>=pA){
            a-=pA; //each branch must have at least 1 thingy (partition the rest however you want)
            ans*= fac[pA-1+a]*invFac[a]%MOD*invFac[pA-1]%MOD;//pA-1+a C a
        }else{
            ans*= fac[pA]*invFac[a]%MOD*invFac[pA-a]%MOD; //pA C a
        }
        ans%=MOD;
//        cerr<<pA-1+a<<" "<<a<<endl;
        pA = newA;
    }
    cout<<ans<<endl;


    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
