// ♬ I got my head out the sunroof ♬


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

/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: 
/*


*/
int N; double P;
double prob(vb seen, int S){
    int T = N;
//    cerr<<S<<endl;
    double res = 1;
    for(bool s: seen){
        if(s){
            res*=double(S)/T;
            S--;
        }else{
            res*=double(T-S)/T;
        }
        T--;
//        cerr<<s<<" ";
    }
//    cerr<<endl;
//    cerr<<res<<endl;

    return res;
}
bool tst(int S){
//    cerr<<prob({1,1,1},S)<<endl;
    return prob({1,1,1},S)+3*prob({1,1,0},S)+3./2*(prob({1,0,0},S))>=P;
}
int main() {
    fast;
    cin>>N>>P;
    int l = 0,h = N;
    while(l<=h){
        int mid = (l+h)/2;
        if(tst(mid)){
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<l<<endl;

    return 0;
}
