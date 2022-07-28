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
        double X,Y; cin>>X>>Y;
        double ang = atan(cbrt(Y/X));

        cout<<setprecision(20)<<fixed<<X/cos(ang)+Y/sin(ang)<<endl;
    }
    
    return 0;
}