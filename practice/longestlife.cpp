// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny

#include <bits/stdc++.h>
#include <iomanip>
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
struct line{
    double sx,sy,m;
    double f(double x){
        return (x-sx)*m+sy;
    }
    double overtaken(line& rl){
        assert(sx<rl.sx);
        double l = rl.sx; //you can only overtake it at the start of the line
        double r = rl.sx+1;
        while(f(r)<rl.f(r)){
            l = r+1;
            r*=2;
        }
        FR(i,600){
            double mid = (l+r)/2;
            if(f(mid)<rl.f(mid)){
                l = mid;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
int main() {
    fast;
    // just don't take the scammy pills (the ones that give you a worse deal than those already on the market)
    ll T,P,C; cin>>T>>P>>C;
    double ans = T;
    deque<line> lines;
    lines.push_back({ 0, 0, 1});
    FR(p,P){
        ll t,dx,dy; cin>>t>>dx>>dy;
        double m = (double)dy/dx;
        while(sz(lines)>1){
            if(lines[0].f(t)>lines[1].f(t))lines.pop_front();
            else break;
        }
        double sy = lines[0].f(t)+C;
        if(m>=lines.back().m)continue; //bad line (but is it >= or just >)
        line c{double(t),sy,m};
        while(sz(lines)>=2){
            //remove outdated (worse) lines
            line& a = lines[sz(lines)-2],&b = lines.back();
            if(a.overtaken(c)<=a.overtaken(b))lines.pop_back();
            else break;
        }
        lines.push_back(c);

    }

    for(auto l:lines){
//        cerr<<l.sx<<" "<<l.sy<<" "<<l.m<<endl;
        ans = max(ans,(T-l.sy)/l.m+l.sx); //try it!

    }
    cout<<setprecision(10)<<fixed<<ans<<endl;



    return 0;
}
