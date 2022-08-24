// ♬ I got my head out the sunroof ♬


#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template<class ...Args>
auto &read(Args &...args) { return (cin >> ... >> args); }

#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
#define mp(a, b)(make_pair(a,b))
#define pb(a) push_back(a)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
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
#define in(r, R) (r>=0&&r<R)

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
ok just don't be dumb; if you need to do something extra and it's too slow, ask yourself if you can use what you already have to do the same thing.

*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: 
/*


*/

int main() {
    fast;
    vi fac(1000001,1);
    FOR(i,2,sz(fac)){
        if(fac[i]==1){
            for(int j = i; j<sz(fac); j+=i){
                fac[j] = i;
            }
        }
    }
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        map<int,int> groups;
        FR(i,N){
            int n; cin>>n;
            int newInt = 1;
            while(n!=1){
                int times = 0;
                int factor = fac[n];
                while(n!=1&&n%factor==0){
                    n/=fac[n];
                    times++;
                }
                if(times%2)newInt*=factor;
            }
            groups[newInt]++;
        }
        int cur = 0;
        int nxt = 0;
        for(auto [k,v]:groups){
            if(v%2==0||k==1){
                nxt+=v;
            }
            cur = max(cur,v);
        }
        nxt = max(nxt,cur);
        int Q; cin>>Q;
        FR(q,Q){
            ll x; cin>>x;
            if(!x)cout<<cur<<endl;
            else cout<<nxt<<endl;
        }



    }

    return 0;
}
