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
void flip(vvi& g, int k){
//    cerr<<"fip "<<k<<endl;
    FR(i,sz(g)){
        swap(g[i][k],g[k][i]);
    }
}
vvi tst(vvi g){
    vi ambiguous;
    FOR(i,0,sz(g)){
        FR(k,i){
            if(g[k][i]!=g[i][k]){

                if(g[k][i]>g[i][k]){
                    //you should swap (you kind of have to) (suboptimal if you don't)
                    flip(g,i);
                }
                goto nxt;
            }
        }
        //ambiguous pos
        ambiguous.pb(i);

        nxt:;
    }
    for(int i: ambiguous){
//        cerr<<i<<endl;
        FOR(k,i+1,sz(g)){
            if(g[i][k]!=g[k][i]){
                if(g[i][k]>g[k][i]){
                    flip(g,i);
                }
                break;
            }
        }
    }
    return g;
}
void print(vvi& g){
    FR(i,sz(g))FR(j,sz(g))cout<<g[i][j]<<" \n"[j==sz(g)-1];
}
int main() {
    fast;

    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vvi g(N,vi(N));
        FR(i,N)FR(j,N)cin>>g[i][j];
//        vi flips = {1,2,4,3};
//        for(int f: flips){

//            flip(g,f);
//        }
        vvi a = tst(g);

        print(a);
    }
    return 0;
}

/*
 *
1
3
2 2 2
1 2 2
1 1 2

1
5
0 1 1 1 1
0 0 1 1 1
0 0 0 1 1
1 1 1 0 0
0 1 1 1 0


0 0 0 1 0
1 0 1 1 1
1 0 0 1 1
1 1 1 0 0
1 1 1 1 0

0 0 0 1 0
1 0 1 1 1
1 0 0 1 1
1 1 1 0 0
1 1 1 1 0
 */