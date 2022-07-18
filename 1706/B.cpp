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
    int READ(T);
    FR(t,T){
        int N; cin>>N;
        vi ans(N,0);
        vi last(N,-1); //latest
        int prev = -1;
        FR(i,N){
            int c; cin>>c; c--;
            int parity = i%2;
            if(last[c]!=parity){
                ans[c]++;
                last[c] = parity;
            }
        }
        FR(c,N){
            cout<<ans[c]<<" \n"[c==N-1];
        }
    }
    return 0;
}