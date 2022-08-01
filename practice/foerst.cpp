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
bool rightTurn(pii a, pii b, pii c){
    complex<int> v1{b.f-a.f,b.s-a.s},v2{c.f-b.f,c.s-b.s};
    return (conj(v1)*v2).imag()<0;

}
void genHull(vpii& pts,vpii& hull){
    for(auto pt:pts){
        while(sz(hull)>=2&&!rightTurn(hull[sz(hull)-2],hull.back(),pt)){
            hull.pop_back();
        }
        hull.push_back(pt);
    }

}
int main() {
    fast;
    int N,D; cin>>N>>D;
    vector<pii> pts;
    FR(i,N){
        int x,y;cin>>x>>y;
        pts.emplace_back(x,y);
    }
    sort(all(pts));
    vpii upper,lower,hull;
    genHull(pts,upper);
    reverse(all(pts));
    genHull(pts,lower);

    hull.insert(hull.end(),all(upper));
    hull.insert(hull.end(),lower.begin()+1,lower.end());
//    for(auto pt:hull){
//        cerr<<pt.f<<" "<<pt.s<<endl;
//    }
    double perim = 0,area = 0;
    FOR(i,1,sz(hull)){
        int dx = hull[i].f-hull[i-1].f,dy = hull[i].s-hull[i-1].s;
        perim+=sqrt(dx*dx+dy*dy);
        area+=hull[i-1].f*hull[i].s-hull[i].f*hull[i-1].s;
    }
    area = abs(area);
    area/=2; //shoelace
    area+=perim*D; //the outside rectangles
    area+=M_PI*D*D; //circle


    perim+=M_PI*2*D; //circle perimeters

    cout<<setprecision(2)<<fixed<<perim<<" "<<area<<endl;

    return 0;
}
