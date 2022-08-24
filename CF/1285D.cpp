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

an extra minute of validating your solution (by trying more cases, for example), can save you a significant amount of coding time.
*/

/*Code Improvements



*/
// TAG: 
/*


*/
int nums[100001];
bool active(int n, int i){
    return (n&(1<<i))>0;
}
int dfs(int l,int r ,int depth = 29){
    if(depth<0)return 0;
    if(active(nums[l],depth)||!active(nums[r],depth)){
        return dfs(l,r,depth-1);
    }
    int j = l+1;
    while(j<=r&&!active(nums[j],depth))j++;
    //j is first active

    return (1<<depth) + min(dfs(l,j-1,depth-1),dfs(j,r,depth-1));
}
int main() {
    fast;
    int N; cin>>N;

    FR(i,N)cin>>nums[i];
    sort(nums,nums+N);
    cout<<dfs(0,N-1)<<endl;

    return 0;
}
