#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;
using pii = pair<int,int>;
using pdd = pair<double,double>;

struct person{
    int height,arm;
};
int main(){
    int T;cin>>T;
    FR(t,T){
        ll N,L; cin>>N>>L;
        vector<person> ps;
        double l = 0,r=1e7;
        FR(i,N){
            int w,h,a; cin>>w>>h>>a;
            L-=w;
            r = min(r,double(h));
            ps.push_back({h,a});

        }
        auto len = [&](double H)->double{
            double res = 0;
            FR(i,N){
                assert(ps[i].height>=H);
                double a = ps[i].height-H;
                double c = ps[i].arm;
                if(a<c){
                    res+=sqrt(c*c-a*a);
                }
            }
            // cerr<<H<<" "<<res<<endl;
            return res*2;
        };
        FR(_,600){
            double mid = (l+r)/2;
            // cerr<<l<<" "<<r<<" "<<mid<<endl;
            // cerr<<len(mid)<<endl;
            if(len(mid)<=L){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout<<setprecision(20)<<fixed<<l<<endl;

    }
    
    return 0;
}