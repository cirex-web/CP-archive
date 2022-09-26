// ♬ I got my head out the sunroof ♬


#include <bits/stdc++.h>
#include<algorithm>
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
#define endl '\n'
/*Insights


*/

/*Debugging
Always check if the range is completely non overlapping first for seg trees

*/

/*Code Improvements



*/
// TAG: 
/*
Changes:
 you can read in from input stream while building seg tree! (X)
 narrow down with iterative rather than recursive after getting in correct range (X)
 optimizing gcd; iterative (X)

 checking bounds/validity before recursing (a bit faster)
 Getting rid of the iterative portion of seg tree query (X) (iterative always faster lol)

 C++20? (bit faster)
 using \n instead of endl? (SIGNIFICANTLY FASTER!!!!!!)
 IO speed issue?
*/
int gcd(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
struct segTree{
    vi ar;
    segTree(int N){
        ar.resize(4*N);
    }
    void build(int i, int tl, int tr){
//        cerr<<i<<" "<<tl<<" "<<tr<<endl;
        if(tl==tr)cin>>ar[i];
        else{
            int tm = (tl+tr)/2;
            build(2*i,tl,tm);
            build(2*i+1,tm+1,tr);
            ar[i] = gcd(ar[2*i],ar[2*i+1]);
        }
    }
    void set(int x, int v, int i, int tl, int tr){
        if(tl==tr){
            assert(x==tl);
            ar[i] = v;
        }else{

            int tm = (tl+tr)/2;
            if(x<=tm)set(x,v,2*i,tl,tm);
            else set(x,v,2*i+1,tm+1,tr);
            ar[i] = gcd(ar[2*i],ar[2*i+1]);
        }
    }
    void get(int l, int r, int v, int& sum, int i = 1, int tl = 1, int tr = -1){
        if(tr==-1)tr = sz(ar)/4; //bruh what
//        cerr<<tl<<" "<<tr<<endl;
        if(sum>1)return;
        if(tl==tr)sum+=ar[i]%v!=0;
        else{

            int tm = (tl+tr)/2;

            if(l<=tm&&ar[2*i]%v)get(l,r,v,sum,2*i,tl,tm);
            if(sum>1)return; //is this the optimization?
            if(r>tm&&ar[i*2+1]%v)get(l,r,v,sum,2*i+1,tm+1,tr);

        }


    }
};
int main() {
    fast;
    int N;cin>>N;
    segTree gcdTree(N);
    gcdTree.build(1,1,N);
//    FR(i,N)cerr<<gcdTree.get(i+1,i+1,2)<<endl;

    int Q; cin>>Q;
    FR(q,Q){
        int t; cin>>t;
        if(t==1){
            int READ(l,r,v);
            int sum = 0;
            gcdTree.get(l,r,v,sum);
            if(sum<=1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            int READ(i,v);
            gcdTree.set(i,v,1,1,N);

        }
    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
