// ♬ I got my head out the sunroof ♬


#include <bits/stdc++.h>

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
    ll READ(N,K);
    string READ(A,B);A+=' ';B+=' ';
    map<pair<string,string>,ll> rng;
    rng[mp(A,B)] = 2;
    ll ans = 0;
    FR(i,N){
        map<pair<string,string>,ll> newrng;
        for(auto [strs,cnt]:rng){
            auto [a,b] = strs;
            if(!cnt)continue;
            cerr<<a<<" "<<b<<endl;
            if(a[0]==b[0])newrng[mp(a.substr(1),b.substr(1))]+=cnt-1;
            else{
                FORE(c,a[0]-'a',b[0]-'a'){
                    char cur = char(c+'a');
                    string top = string(sz(a)-2,'a')+" ";
                    string bot = string(sz(a)-2,'b')+" ";
                    if(cur==a[0]){
                        newrng[mp(a.substr(1),bot)]+=cnt-1;
                    }else if(cur==b[0]){
                        newrng[mp(top,b.substr(1))]+=cnt-1;
                    }else{
                        assert(0);
                        newrng[mp(string(sz(a)-2,'a'),string(sz(a)-2,'b'))]+=cnt-1;
                    }
                }
            }


        }
        ll tot = 0;
        for(auto [_,cnt]:newrng){
            cerr<<_.f<<" "<<_.s<<" "<<cnt<<endl;
            tot+=cnt;
        }

        ans+=(N-i)*min(tot,K);
        K-=tot;
        if(K<=0)break;
        swap(rng,newrng);
    }
    cout<<ans<<endl;

    return 0;
}
