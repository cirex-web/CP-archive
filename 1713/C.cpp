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

const int INVALID = INT_MIN;
int main() {
    fast;
    vi dp(1e5+1,INVALID);
    FR(i,sz(dp)){
        int low = sqrt(i);
        if(low*low!=i)low++;
        while(low*low<=2*i){
            int j = low*low-i-1; //next thing
            if(j<0||dp[j]!=INVALID){
                dp[i] = j;
                break;
            }
            low++;
        }
    }
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;N--;
        if(dp[N]==INVALID){
            cout<<-1<<endl;
        }else{
            vpii ans;
            while(N!=-1) {
                ans.pb(mp(dp[N] + 1, N));
                N = dp[N];
            }
            reverse(all(ans));
            for(auto [a,b]:ans){
                int root = sqrt(a+b);
                assert(root*root==a+b);
                ROF(i,b,a){
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
