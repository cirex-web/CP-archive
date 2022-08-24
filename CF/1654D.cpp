// ♬ I got my head out the sunroof ♬


#include <bits/stdc++.h>
#include <numeric>

using namespace std;

template<class ...Args>
auto &read(Args &...args) { return (cin >> ... >> args); }

#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
#define mp(a, b)(make_pair(a,b))
#define pb(a) push_back(a)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); (i) < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define RF(i, a) ROF(i,a,0)
#define FR(i, a) FOR(i,0,a)
#define FRE(i, a) FORE(i,0,a)

#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(x) ((int)(x.size()))
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define in(r, R) ((r)>=0&&(r)<R)

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvs = vector<vs>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvvi = vector<vvi>; //are you sure about this?
using vvvl = vector<vvl>; //are you sure about this?



ll MOD = 1000000007;


template<typename T>
void setmax(T &a, T b) { if (b > a) a = b; }

template<typename T>
void setmin(T &a, T b) { if (b < a) a = b; }

/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG:
/*


*/
ll expo(ll n, ll pow){
    if(pow<=0)return 1;
    ll res = pow%2?n:1;
    ll half = expo(n,pow/2);
    return res*half%MOD*half%MOD;

}
ll inv(ll n){
    return expo(n,MOD-2);
}
int main() {
    fast;
    int T; cin>>T;
    MOD = 998244353;
    FR(t,T){
        int N; cin>>N;
        map<pii,pll> edge;
        vvi g(N);
        FR(i,N-1){
            int READ(a,b,x,y);a--;b--;
            edge[mp(a,b)] = mp(x,y);
            edge[mp(b,a)] = mp(y,x);
            g[a].pb(b);
            g[b].pb(a);
        }
        auto dfs = [&](auto&& self,int a, int par)->pll{
            vl sums,nums;
            ll lcm = 1;
            for(int b: g[a]){
                if(b==par)continue;
                auto [val,sum] = self(self,b,a);

                auto [r1,r2] = edge[mp(b,a)];
                ll newVal = val*inv(gcd(val,r1))%MOD*r1%MOD;
                sums.pb(newVal*inv(val)%MOD*sum%MOD); //assuming val is already included in sum
                ll curVal = newVal*inv(r1)%MOD*r2%MOD;
                nums.pb(curVal);
                lcm = lcm*inv(gcd(lcm,curVal))%MOD*curVal%MOD; //can you find lcm while under mod??
            }
            ll sum = lcm;
            FR(i,sz(sums)){
                ll fac = lcm*inv(nums[i])%MOD;
                sum+=sums[i]*fac%MOD;
                sum%=MOD;
            }
//            cerr<<sum<<endl;
//            cerr<<a<<" "<<lcm<<" "<<sum<<endl;
            return {lcm,sum};
        };
        cout<<dfs(dfs,0,-1).s<<endl;
    }

    return 0;
}
