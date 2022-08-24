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

int main() {
    fast;
    int N; cin>>N;
    vvi sq(N,vi(N,0));
    auto add = [&](int x, int y){
        if(!in(x,N)||!in(y,N))return false;
//        cerr<<x<<" "<<y<<endl;
//        cerr<<sq[x][y]<<endl;
        return (++sq[x][y])==4;
    };
    int player = 0;
    vi scores(2,0);
    FR(i,2*N*(N-1)){
        int READ(x1,y1,x2,y2);x1--;y1--;x2--;y2--;
        cout<<(player==0?'A':'B');
        if(x1>x2||y1<y2){
            swap(x1,x2); swap(y1,y2);
        }
        int captured;
        if(x1==x2){
            captured=add(x1-1,y1)+add(x1,y1);
        }else{
            captured = add(x1,y1+1)+add(x1,y1);
        }
        if(captured){
            scores[player]+=captured;
        }else{
            player^=1;
        }

    }
    cout<<endl;
    cout<<scores[0]<<" "<<scores[1]<<endl;

    return 0;
}
