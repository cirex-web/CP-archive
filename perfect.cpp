#include <bits/stdc++.h>
#include <iomanip>
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
double dist(pdd& a, pdd& b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int main(){
    int T;cin>>T;
    FR(t,T){
        int N; cin>>N;
        vector<pdd> pts = {{0,0}};
        FR(i,N){
            double x,y;cin>>x>>y;
            pts.push_back({x,y});
        }
        sort(all(pts));
        double ans = 0;
        FOR(i,1,sz(pts)){
            ans+=dist(pts[i],pts[i-1]);
        }
        cout<<setprecision(20)<<fixed<<ans<<endl;
    }
    
    return 0;
}