// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny

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

/*


*/

vi getChildren(vvi& g){
    int N = sz(g);
    vi res(N,-1);
    vi deps(N,0);
    FR(i,N){
        for(int j: g[i]){
            deps[j]++;
        }
    }
    vi q;
    FR(i,N){
        if(!deps[i])q.push_back(i);
    }
    FR(i,sz(q)){
        int a = q[i];
        if(i==sz(q)-1)res[a]=N-i-1;
        for(int b: g[a]){
            if(--deps[b]==0)q.push_back(b);
        }
    }
    return res;

}

int main() {
    fast;
    int READ(N,M);
    vvi g(N),rg(N);
    vi deps(N,0);
    FR(i,M){
        int a,b;cin>>a>>b;a--;b--;
        g[a].pb(b);
        rg[b].pb(a);
    }

    int ans = 0;
    vi r1 = getChildren(g),r2 = getChildren(rg);
    FR(i,N){
        if(r1[i]+r2[i]==N-1)ans++;
    }
    cout<<ans<<endl;


    return 0;
}
