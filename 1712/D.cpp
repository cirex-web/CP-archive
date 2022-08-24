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
    int T; cin>>T;
    FR(t,T){
        int READ(N,K);
        vi ar(N); FR(i,N)cin>>ar[i];
        int consec = 0;
        FR(i,N-1){
            setmax(consec,(min(ar[i],ar[i+1])));
        }
        vi sorted = ar;sorted.pb(1e9);
        sort(all(sorted));
        int ans = -1;
        FR(i,N){
            int curConsec = consec;
            if(i<N-1)setmax(curConsec,ar[i+1]);
            if(i)setmax(curConsec,ar[i-1]);
            int j = lower_bound(all(sorted),ar[i])-sorted.begin();
            int minVal = sorted[K-1];

            if(j<=K-1){
                minVal = sorted[K];
            }
//            cerr<<curConsec<<" "<<minVal<<endl;
            ans = max(ans,min(curConsec,2*minVal));

        }
        FR(i,N-1){
            if(K<2)break;
            int i1 = lower_bound(all(sorted),ar[i])-sorted.begin();
            int i2 = lower_bound(all(sorted),ar[i+1])-sorted.begin();
            if(i1==i2)i2++;
            int nK = K-2;
            sorted[i1] = 0;
            sorted[i2] = 0;
            if(i1<=nK)nK++;
            if(i2<=nK)nK++;
            while(nK<=N&&sorted[nK]==0)nK++;
            ans = max(ans,min(int(1e9),2*sorted[min(N,nK)]));
            sorted[i1] = ar[i];
            sorted[i2] = ar[i+1];
//            FR(i,N)cerr<<sorted[i]<<" \n"[i==N-1];
        }
        assert(ans!=-1);
        cout<<ans<<endl;
    }

    return 0;
}
