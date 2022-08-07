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
double dist(int x1, int y1, int x2, int y2){
    return sqrt(ll(x1-x2)*(x1-x2)+ll(y1-y2)*(y1-y2));
}
int main() {
    fast;
    int READ(Ax,Ay,Bx,By,X,Y,N);
    vpii pts;
    double totalDist = 0,ans = 1e20;
    FR(i,N){
        int READ(x,y);
        pts.push_back({x,y});
        totalDist+=2*dist(X,Y,x,y);
    }
    auto gen = [&](int x1, int y1){
        vector<pair<double,int>> res;
        FR(i,sz(pts)){
            auto [x2,y2] = pts[i];
            double saved = dist(X,Y,x2,y2)-dist(x1,y1,x2,y2);
            res.emplace_back(saved,i);
        }
        sort(all(res)); reverse(all(res));
        return res;
    };
    auto d1 = gen(Ax,Ay),d2 = gen(Bx,By);
    FR(i,2){
        swap(d1,d2);
        ans = min(ans,totalDist-d1[0].f); //just by itself
        FR(j,min(2,sz(d2))){
            if(d2[j].s==d1[0].s)continue;
            ans = min(ans,totalDist-d1[0].f-d2[j].f);
        }
    }
    cout<<setprecision(20)<<ans<<endl;

    return 0;
}
