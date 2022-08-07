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

int main() {
    fast;
    int READ(N,B);
    string s; cin>>s;
    vi white(N+1,0);
    vi black; //where you'll end up if you invest i black
    FR(i,N){
        white[i+1]=white[i]+(s[i]=='W');
        if(s[i]=='B'){
            black.push_back(i);
        }
    }
    int ans = 0;
    FRE(b,B){
        int left = black[b],right = black[sz(black)-1-(B-b)];
//        cerr<<left<<" "<<right<<endl;
        ans = max(ans,white[left]+(white[N]-white[right]));
    }
    cout<<ans<<endl;


    return 0;
}
