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
struct segTree{
    vi t;
    segTree(int N){
        t.resize(4*N); //0s?

    }
    void push(int i){
        if(t[i]){

            t[2*i] = t[2*i+1] = t[i];
            t[i] = 0;
        }

    }
    void set(int i, int tl, int tr, int l, int r, int x){
        if(r<tl||tr<l)return;
        if(l<=tl&&tr<=r)t[i] = x;
        else{
            push(i);
            int tm = (tl+tr)/2;
            set(2*i,tl,tm,l,r,x);
            set(2*i+1,tm+1,tr,l,r,x);
        }
    }
    int get(int i, int tl, int tr, int pos){
//        cerr<<i<<" "<<tl<<" "<<tr<<" "<<pos<<endl;
        if(tl==tr){
//            cerr<<tl<<" "<<pos<<endl;
            assert(tl==pos);
            return t[i];
        }
        int mt = (tl+tr)/2;
        push(i); //whatever you have here I guess ?
        if(pos<=mt){
            return get(2*i,tl,mt,pos);
        }else{
            return get(2*i+1,mt+1,tr,pos);
        }
    }

};
struct ev{
    int l,r,w;
};
int main() {
    fast;
    int READ(N,M);
    vector<ev> evs;
    FR(i,M){
        int READ(l,r,x);
        evs.push_back({l,r,x});
    }
    reverse(all(evs));
    segTree tree(N);
    for(auto [l,r,x]:evs){
        int prev = tree.get(1,1,N,x);
        tree.set(1,1,N,l,r,x);
        tree.set(1,1,N,x,x,prev);
    }
    FORE(i,1,N){
        cout<<tree.get(1,1,N,i)<<" \n"[i==N];
    }


    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
