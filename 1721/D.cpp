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

do structs suck in terms of memory? no
*/

/*Code Improvements



*/
// TAG: 
/*


*/

int main() {
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vector<pair<vi,vi>> groups(1,{vi(N),vi(N)});
        vector<pair<vi,vi>> newGroups;
        FR(i,N)cin>>groups[0].f[i];
        FR(i,N)cin>>groups[0].s[i];
        int ans = 0;
        ROF(i,29,0){
            bool ok = true;
            for(auto& g:groups){
                auto& [a,b] = g;
                pair<vi,vi> g10,g01; //a to b
                FR(j,sz(a)){
                    if((a[j]&(1<<i)))g10.f.pb(a[j]);
                    else g01.f.pb(a[j]);
                    if((b[j]&(1<<i)))g01.s.pb(b[j]);
                    else g10.s.pb(b[j]);
                }
                if(sz(g10.f)!=sz(g10.s)){
                    ok = false;
                    break;
                }
                newGroups.push_back(std::move(g10));
                newGroups.push_back(std::move(g01));
            }
            if(ok){
                ans+=1<<i;
                swap(groups,newGroups);
            }
            if(sz(groups)==N)break;
            newGroups.clear();

        }
        cout<<ans<<endl;
    }

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
