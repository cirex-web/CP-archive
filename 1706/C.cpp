//coding in the freezer

#include <bits/stdc++.h>
using namespace std;
 
template <class ...Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
 
#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
 
#define mp(a,b)(make_pair(a,b))
#define pb(a) push_back(a)
#define FORE(i,a,b) for (int i = (a); i <= (b); ++i)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (a); i >= (b); --i)
#define RF(i,a) ROF(i,a,0)
#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FORE(i,0,a)
 
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(x) ((int)(x.size()))
#define f first
#define s second
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define in(r,R) (r>=0&&r<R)
 
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
 
 
template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }
template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }

int main(){
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N; vi ar(N);
        FR(i,N){
            cin>>ar[i];
        }
        ll ans = 0;
        auto calc = [&](int i){
            return max(0,1+max(ar[i-1]-ar[i],ar[i+1]-ar[i]));
        };
        // auto test = [&](int i){
        //     vl cost(N/2)
        //     while(i+1<N){
        //         cost+=max(0,1+max(ar[i-1]-ar[i],ar[i+1]-ar[i]));
        //         i+=2;
        //     }
        //     return cost;
        // };
        if(N%2==1){
            for(int i = 1; i+1<N;i+=2){
                ans+=calc(i);
            }
            cout<<ans<<endl;
        }else{
            vl pre(N/2,0),suf(N/2,0);
            for(int i = 1; i<N-1; i+=2){
                int pos = (i+1)/2;
                pre[pos]=pre[pos-1]+calc(i);
            }
            for(int i = N-2;i>0;i-=2){
                int pos = (i-1)/2; //0 contains everything
                suf[pos] = suf[pos+1]+calc(i);
            }
            ans = LLONG_MAX;
            FR(i,sz(pre)){
                cerr<<pre[i]<<" "<<suf[i]<<endl;
                setmin(ans,pre[i]+suf[i]);
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}