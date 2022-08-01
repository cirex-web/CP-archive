// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny

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

/*


*/
struct meeting{
    int s,e1,e2;
};
int main() {
    fast;
    int N; cin>>N;
    vector<meeting> meetings;
    FR(i,N){
        int s,l,h;cin>>s>>l>>h;
        meetings.push_back({s,s+l,s+h});
    }
    vd dp(N,0);
    ROF(i,N-1,0){
        int l1 = meetings[i].e1,r1 = meetings[i].e2;
        int l2 = 0,r2; //bounds are inclusive

        dp[i] = 1; //take the meeting
        FOR(j,i+1,N){
            r2 = meetings[j].s;
            int l = max(l1,l2),r = min(r1,r2);
            if(l<=r){
                //valid period
                dp[i]+=double(r-l+1)/(r1-l1+1)*dp[j];
            }

            l2 = r2+1;  //locked probability window to past the start of meeting j
                        // (shouldn't restrict anything cuz other meetings that start earlier are factored into dp[<=j]
        }

        //maybe the better option was to not even take this meeting
        if(i<N-1)dp[i] = max(dp[i],dp[i+1]);
    }
    cout<<setprecision(9)<<fixed<<dp[0]<<endl;

    return 0;
}
