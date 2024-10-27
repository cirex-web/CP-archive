
// Problem: Letter Blocks
// Contest: Google Coding Competitions - Round 1C 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000877b42/0000000000afe6a1
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// Date started: 2022-04-30 05:12:39
// Burnout sucks

// The difference between a segmentation fault and a segment tree
// is that I only know how to produce the former.

#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iterator>
#include <cstring>
#include <fstream>
#include <map>
#include <bitset>
#include <cassert>
#include <stdlib.h>
#include <climits>
#include <stack>
#include <complex> 
#include <iomanip>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

//fancy
template < typename T > istream & operator >> (istream & is, vector < T > & v) {
  for (auto & i: v) is >> i;
  return is;
}
template < typename T > ostream & operator << (ostream & os,
  const vector < T > & v) {
  for (auto & i: v) os << i << " ";
  return os;
}
template < typename T > istream & operator >> (istream & is, pair < T, T > & v) {
  is >> v.first >> v.second;
  return is;
}
template < typename T > ostream & operator << (ostream & os,
  const pair < T, T > & v) {
  os << v.first << " " << v.second;
  return os;
}

#define the meaning of life in at most 42 words

#define fa(a,b)(memset(a,b,sizeof(a)));
#define fill2d(vec,val) for(auto &v:vec)fill(all(v),val)
#define mp(a,b)(make_pair(a,b))
#define pb(a) push_back(a)
#define FORE(i,a,b) for (int i = (a); i <= (b); ++i)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (a); i >= (b); --i)
#define RF(i,a) ROF(i,a,0)
#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FORE(i,0,a)
#define FREE(yourself) FRE(yourself,0)

#define LFORE(i,a,b) for (ll i = (a); i <= (b); ++i)
#define LFOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define LROF(i,a,b) for (ll i = (a); i >= (b); --i)
#define LFR(i,a) LFOR(i,0,a)
#define LFRE(i,a) LFORE(i,0,a)

#define p (pi())
#define flag (cout<<"here"<<endl)
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(x) ((int)(x.size()))
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

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

const int dx[8] = {1,0,-1,0,1,1,-1,-1}; //first 4 are normal
const int dy[8] = {0,1,0,-1,1,-1,1,-1};
ll MOD = 1000000007;
const ll NMOD = 1000000009;

const int AR_MAX = (1 << 7) - 1; //when using memeset
const int AR_MAX_VAL = 2139062143;
//^ Not recommended unless 
//  there's no other way do to what you need to do
const double PI  =3.141592653589793238463;
const double EPS = 1e-9;


template<class Q>
typename Q::value_type pop(Q& q) {
    auto result = q.front();
    q.pop();
    return result;
};

//reading input the "java" way 
//(aka with method calls)
int pi() {
	int N;
	cin >> N;
	return N;
}
ll pl() {
	ll N;
	cin >> N;
	return N;
}
char pc() {
	char c;
	cin >> c;
	return c;
}
string ps() {
	string s;
	cin >> s;
	return s;
}


//other
template<class T1, class T2>
ll powf(T1 a, T2 b) {
	if(b<0)return 0;
	if (b == 0)return 1;
	ll val = powf(a, (ll)(b / 2));
	if (b & 1) {

		return ((val * val) % MOD * a) % MOD;
	} else {
		return (val * val) % MOD;
	}
}
string bin(int n, int digits) {
	string s = bitset<32>(n).to_string();
	s.erase(0, s.length() - digits);
	return s;
}
void IO(string fileName) {
	freopen((fileName + ".in").c_str(), "r", stdin);
	freopen((fileName + ".out").c_str(), "w", stdout);
}
ll cp(complex<ll> a, complex<ll> b){
	return (conj(a)*b).imag();
}
bool eq(double a, double b){
	return fabs(a-b)<=EPS;
}
void add(ll& a, ll b){
	a+=b;
	a%=MOD;
	if(a<0)a+=MOD;
}
void mul(ll& x, ll y){
	x = (x*y)%MOD;
}
void sub(ll& a, ll b){
	add(a,-b);
}

/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: shortest paths
int main() {
	fast;
	int T = p;
	FR(t,T){
		cout<<"Case #"<<t+1<<": ";
		int N = p;multiset<string> strs;
		FR(i,N)strs.insert(ps());
		FR(i,26){
			char c = i+'A';
			string res,left="",right="";
			vs rem;
			for(string s:strs){
				if(s.find(c)!=string::npos){
					if(s[0]==c&&s[sz(s)-1]!=c){
						right+=s;
					}else if(s[0]!=c&&s[sz(s)-1]==c){
						left+=s;
					}else{
						res+=s;
					}
					rem.pb(s);
					
				}
			}
			for(string s: rem)strs.erase(strs.find(s));
			res = left+res+right;
			vi f(26,0);
			int segs = 0;
			for(int i =0 ; i<sz(res);){
				
				int j = i;
				while(j<sz(res)&&res[j]==res[i])j++;
				if(++f[res[i]-'A']>1){
					cout<<"IMPOSSIBLE"<<endl;
					goto nxt;
				}
				
				i = j;
			}
			
			cerr<<res<<endl;
			strs.insert(res);
		}
		
		for(string s:strs){
			cout<<s;
		}
		cout<<endl;
		
		nxt:;
		
	}
	return 0;
}