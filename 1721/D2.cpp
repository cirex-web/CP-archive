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

do structs suck in terms of memory? no
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
        vi aGroup(N,0);
        vi bGroup(N,0);
        vi A(N),B(N);
        FR(i,N)cin>>A[i];
        FR(i,N)cin>>B[i];
        vi a(N),b(N);
        FR(i,N){
            a[i] = i;
            b[i] = i;
        }
        int ans = 0;
        int g = 1;
        ROF(bit,29,0){
            cerr<<bit<<endl;
            sort(all(a),[&](int i, int j){
                if(aGroup[i]!=aGroup[j])return aGroup[i]<aGroup[j];
                return (i&(1<<bit))<(j&(1<<bit));
            });
            sort(all(b),[&](int i, int j){
                if(bGroup[i]!=bGroup[j])return bGroup[i]<bGroup[j];
                return (i&(1<<bit))>(j&(1<<bit));
            });
            vi newBgroup(N,0);
            vi newAgroup(N,0);

            for(int i = 0; i<sz(a);){
                int j1 = i, j2 = i;
                int sg = aGroup[a[i]];
                while(j1<sz(a)&&aGroup[a[j1]]==sg&&!(A[a[j1]]&(1<<bit)))j1++;
                while(j2<sz(b)&&bGroup[b[j2]]==sg&&(B[b[j2]]&(1<<bit)))j2++;
                if(j1!=j2)goto nxt;
                while(j2<sz(b)&&bGroup[b[j2]]==sg)j2++;
                FOR(k,i,j1){
                    newAgroup[a[k]] = g;
                    newBgroup[b[k]] = g;
                }
                g++;
                FOR(k,j1,j2){
                    newAgroup[a[k]] = g;
                    newBgroup[b[k]] = g;
                }
                i = j2;
            }

            ans+=1<<bit;
            swap(aGroup,newAgroup);

            swap(bGroup,newBgroup);
            nxt:;
        }
        cout<<ans<<endl;
    }

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
