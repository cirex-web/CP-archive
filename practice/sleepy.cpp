// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny

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

/*

4
1 2 4 3
*/
struct BIT{
    vi ar; int n = 0;
    explicit BIT(int N){
        ar.resize(N+1,0);
    }
    void set(int i){
        for(;i<sz(ar);i+=i&-i)ar[i]++;
        n++;
    }
    int get(int i){
        int sum = n;
        for(;i;i-=i&-i)sum-=ar[i];
        return sum;
    }
};
void IO(string fileName) {
    freopen((fileName + ".in").c_str(), "r", stdin);
    freopen((fileName + ".out").c_str(), "w", stdout);
}
int main() {
//    IO("sleepy");
    fast;
    int N; cin>>N;
    vi ar(N); FR(i,N)cin>>ar[i];
    BIT bit(N);
    int j = N-1;
    while(j>0&&ar[j-1]<ar[j])j--;
    FOR(i,j,N)bit.set(ar[i]);

    cout<<j<<endl;
    FR(i,j){
        int larger = bit.get(ar[i]);
        cout<<N-1-larger<<" \n"[i==j-1];
        bit.set(ar[i]);
    }



    return 0;
}
