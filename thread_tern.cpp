#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;
// typedef double long double;
//ternary search prob

int main(){
    int T;cin>>T;
    FR(t,T){
        int X,Y; cin>>X>>Y;
        auto calc = [&](double theta){
            return X/cos(theta)+Y/sin(theta);
            // return sqrt((w*w)*(Y*Y/((w-X)*(w-X))+1));
        };
        //what bounds??
        double l = 1e-6,r=3.14159265358979323984/2-(1e-6);
        FR(_,600){
            double m1 = l+(r-l)/3;
            double m2 = r-(r-l)/3;
            if(calc(m1)>calc(m2)){
                l = m1;
            }else{
                r = m2;
            }

        }
        cout<<setprecision(20)<<fixed<<calc(l)<<endl;
    }
    
    return 0;
}