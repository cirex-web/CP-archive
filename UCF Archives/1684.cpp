// Problem: Dynamic Range Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1648
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Date started: 2022-07-12 21:36:30
// 
// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny
 
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
 
/*Insights
 
 
*/
 
/*Debugging
 
 
*/
 
/*Code Improvements
bruh don't forget to initialize stuff
 
 
*/
// TAG: 
struct Node{
	ll sum = 0;
	int l,r;
	ll lazy = 0;
	Node* left = NULL, *right = NULL;
	Node(int lv, int rv){
		// cerr<<"init "<<lv<<" "<<rv<<endl;
		l = lv;
		r = rv;
 
	}
	void increment(int vl, int vr, ll amount){
		// cerr<<l<<" "<<r<<endl;
		if(vl>r||vr<l)return;
		if(vl<=l&&vr>=r){
			lazy+=amount;
			sum+=(r-l+1)*amount;
			return;
		}
		push();

		left->increment(vl,vr,amount);
		right->increment(vl,vr,amount);
		sum = left->sum+right->sum;
		
	}
	void push(){
		assert(r-l+1>1);
		int mid = (l+r)/2;
		// cerr<<"push!"<<endl;
		if(!left){ //works?
			
			left = new Node(l,mid);
			right = new Node(mid+1,r);
		}
        
		if(lazy!=0){
			// cerr<<"inc?"<<" "<<lazy<<endl;
			left->increment(l,mid,lazy);
			right->increment(mid+1,r,lazy);
			lazy = 0;
		}
	}
	ll sum_range(int nl, int nr){
		if(nl>r||nr<l)return 0;
		if(nl<=l&&nr>=r)return sum;

		push();

		return left->sum_range(nl,nr)+right->sum_range(nl,nr);
	}

};

struct BIT{
	vl ar;

    [[maybe_unused]] BIT(int N){
		ar.resize(N+1,0);
	}
	void add(int i, int amount){
		i++;
		while(i<sz(ar)){
			ar[i]+=amount;
			i+=i&-i;
		}
	}
	ll get(int i){
		i++;
		ll sum = 0;
		while(i){
			sum+=ar[i];
			i-=i&-i;
		}
		return sum;
	}
};

int main() {
	fast;
	int READ(N,Q);
	BIT bit(N);
	vi ar(N);
    // FR(i,1000){
    //     seg.increment(0,0,i%2?1:-1);
    // }
    // cout<<seg.sum_range(0,0)<<endl;
	// seg.increment(0,3,3);
	// seg.increment(2,5,2);
	// // 0 1 2 3 4 5
	// // 3 3 5 5 2 2
	// FR(i,6){
		// cout<<seg.sum_range(i,i)<<endl;
	// }
	FR(i,N){
		cin>>ar[i];
		bit.add(i,ar[i]);
	}
	FR(q,Q){
		ll T,A,B; cin>>T>>A>>B;
		if(T==1){
			A--;
			ll delt = B-ar[A];
			ar[A] = B;
			bit.add(A,delt);
		}else{
			cout<<bit.get(B-1)-bit.get(A-2)<<endl;
		}
	}
	return 0;
}