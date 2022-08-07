// ♬ I got my head out the sunroof ♬

#define _USE_MATH_DEFINES

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

/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: 
/*


*/
void rotate(pdd& pt, double ang){
    auto [x,y] = pt;
    ang=ang/180*M_PI;
//    cerr<<pt.first<<" "<<pt.second<<endl;

    pt = {cos(ang)*x-sin(ang)*y,sin(ang)*x+cos(ang)*y};
//    cerr<<pt.first<<" "<<pt.second<<endl;
}
struct seg{
    double x1,y1,x2,y2,m;
    seg(pdd a, pdd b){
        tie(x1,y1) = a;
        tie(x2,y2) = b;
        m = (y2-y1)/(x2-x1);
    }
    double y(double x) const{
        double res = y1+m*(x-x1);
        if(res<min(y1,y2)||res>max(y1,y2)){
            return NAN;
        }
        return res;
    }
    double x(double y) const{
        double res = (y-y1)/m+x1;
        if(res<min(x1,x2)||res>max(x1,x2))return NAN;
        return res;
    }
};
struct side{
    bool vert; double val;
};
int main() {
    fast;
    double W,H,ang; cin>>W>>H>>ang;
//    if(W<H)swap(W,H); //TODO necessary?
    vector<pdd> pts = {{W/2,-H/2},{W/2,H/2},{-W/2,H/2},{-W/2,-H/2}};
    ang = min(ang,180-ang);
    cout<<setprecision(20);
    if(fabs(90-ang)<1e-9){
        cout<<min(W,H)*min(W,H)<<endl;
    }else if(fabs(ang)<1e-9){
        cout<<W*H<<endl;
    }else{
        for(auto& pt:pts){
            rotate(pt,ang);
        }
        vector<seg> segs;
        FR(i,sz(pts)){
            segs.emplace_back(pts[i],pts[(i+1)%sz(pts)]);
        }
        vector<pdd> intersections;
        vector<side> sides = {{true,W/2},{false,H/2},{true,-W/2},{false,-H/2}};
        int prevSide = 0;
        for(auto seg: segs){
            int latestSide = prevSide;
            FR(i,4){
                int sideIndex = (prevSide+i)%sz(sides);
                side cur = sides[sideIndex];
                if(cur.vert){
                    double y = seg.y(cur.val);
                    if(!isnan(y)){
                        intersections.emplace_back(cur.val,y);
                        latestSide = sideIndex;
                    }
                }else{
                    double x = seg.x(cur.val);
                    if(!isnan(x)){
                        intersections.emplace_back(x,cur.val);
                        latestSide = sideIndex;
                    }

                }
            }
//            cerr<<latestSide<<endl;
            prevSide = latestSide;
        }
        intersections.pb(intersections[0]);
        double area = 0;
        FOR(i,1,sz(intersections)){
            auto [x1,y1] = intersections[i-1];
            auto [x2,y2] = intersections[i];
            area+=x2*y1-y2*x1;
        }
        area = fabs(area)/2;
        cout<<area<<endl;
    }

    return 0;
}

