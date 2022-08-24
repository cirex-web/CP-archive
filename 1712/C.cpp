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

Implementation for this was bad..

if you want to check if element exists in map, use .count instead of accesssing it (if you do it creates it if it isn't there)
*/

/*Code Improvements



*/
// TAG: 
/*


*/

int main() {
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vi ar(N); FR(i,N)cin>>ar[i];
        map<int,bool> has;
        vb sorted(N+1); sorted[N] = true;
        ROF(i,N-1,0){
            if(i<N-1&&ar[i]>ar[i+1])sorted[i] = false;
            else sorted[i] = sorted[i+1];
        }

        for(int i = 0; i<=N;){
//            cerr<<t<<" "<<i<<" "<<sorted[i]<<endl;
            if(sorted[i]){
                //chk for dupes
                int reach = -1;
                FOR(j,i,N){
                    if(has.count(ar[j])){ //use has count!!
                        reach = j;
                    }
                }
                if(reach==-1){
                    cout<<sz(has)<<endl;
                    break;
                }else{
                    FORE(j,i,reach)has[ar[j]] = true;
                    i = reach+1;
                }
            }else{
                has[ar[i]] = true;
                i++;
            }
        }

    }

    return 0;
}
