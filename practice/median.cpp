// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny

#include <bits/stdc++.h>

using namespace std;

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

10 3
*/

int main() {
    fast;
    vs res;
    int N,T; cin>>N>>T;
    vi ans;
    function<void(int,int,int)> dfs = [&](int n,int cntLeft, int sum){
//        cerr<<n<<" "<<cntLeft<<" "<<sum<<endl;
        if(sum>T||n*cntLeft<T-sum){
            return;
        }
        if(n==-1){
            if(cntLeft==0&&sum==T){
//                    assert(sz(ans)==N-i+1);
//                    for(auto a:ans)cerr<<a<<" ";
//                    cerr<<endl;
                string curRes(N,'A');
                int pos = N-1;
                ans.push_back(0); //also for the padding at the end
                FOR(j,1,sz(ans)){
                    FR(k,ans[j-1]-ans[j]){ //if there's any differences
                        curRes[pos]='B';pos--;
                    }
                    pos--;
                }
                ans.pop_back();
                res.push_back(curRes);
//                    cerr<<curRes<<endl;
            }
            //process ans
        }else{
            FRE(j,cntLeft){
                //# of n to take
                if(j)ans.push_back(n);
                dfs(n-1,cntLeft-j,sum+n*j);

            }
            FR(j,cntLeft){
                //undo everything
                ans.pop_back();
            }
        }
    };
//    FORE(i,N/2,N/2){
//        //number of 1s added (aka max cap)
//         = {i}; //just slap one on here for reference
//
//        dfs(i,N-i,0);
//
//    }

//    for(auto re:res){
//        cerr<<re<<endl;
//    }
    if(N%2==0){
        ans.push_back(N/2);
        dfs(N/2,N/2,0);
        assert(sz(res)&1);
        cout<<res[sz(res)/2]<<endl;
    }else{
        ans.push_back(N/2);
        dfs(N/2,N-N/2,0);

        ans[0]++; //for the next one
        dfs(N/2+1,N-(N/2+1),0);
        sort(all(res));
        assert(sz(res)^1);
        cout<<res[sz(res)/2-1]<<endl;
        cout<<res[sz(res)/2]<<endl;
    }
    /*
AAAAAAAABABBBABBBBBBB

AAAAAAAABBABABBBBBBBB
     *
     */
// 21 5 is sus
// 60 900
    return 0;
}
