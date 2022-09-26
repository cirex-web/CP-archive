// ♬ I got my head out the sunroof ♬


#include <bits/stdc++.h>
#include <numeric>
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
#define endl '\n'
struct node{
    node * c[2];
    int lazy = 0;
    int val = -1;
    int l1,r1;
    node(int l, int r){
        l1 = l; r1 = r;
        FR(i,2)c[i] = nullptr;
    }
    void upd(int l2, int r2, int v){
        if(r2<l1||r1<l2)return;
        if(l2<=l1&&r1<=r2){
            val = v;
//            cerr<<val<<endl;
            lazy = v;
        }else{
            push();
            FR(i,2)c[i]->upd(l2,r2,v);
            val = gcd(c[0]->val,c[1]->val);
        }
//        cerr<<l1<<" "<<r1<<" "<<val<<endl;
    }
    int get(int l2, int r2){
        if(r2<l1||r1<l2)return 0;
        if(l2<=l1&&r1<=r2)return val;
        else {
            push();
            return gcd(c[0]->get(l2,r2),c[1]->get(l2,r2));
        }
    }
    void push(){
        if(!c[0]){
            int m = (l1+r1)/2;
            c[0] = new node(l1,m);
            c[1] = new node(m+1,r1);
        }
        if(lazy){
            FR(i,2)c[i]->upd(l1,r1,lazy);
            lazy = 0;
        }
    }
};
int main() {
    fast;
    int N;cin>>N;
    node gcdRoot(1,N);

    FR(i,N){
        int n; cin>>n;
        gcdRoot.upd(i+1,i+1,n);
    }

    int Q; cin>>Q;
    FR(q,Q){
        int t; cin>>t;
        if(t==1){
            int READ(l,r,v);
            int bl = l, br = r;
            while(bl<=br){
                int mid = (bl+br)/2;
                if(gcdRoot.get(l,mid)%v==0){
                    bl = mid+1;
                }else{
                    br = mid-1;
                }
            }
            int firstPos = bl;
            if(firstPos+1>r||gcdRoot.get(firstPos+1,r)%v==0){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            int READ(i,v);
            gcdRoot.upd(i,i,v);
        }
    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
