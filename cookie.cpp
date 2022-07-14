#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)


int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        ll A,B,C,P; cin>>A>>B>>C>>P;
        vl ar = {A,B,C}; sort(all(ar));
        // assert(2*P<=A+B+C);
        cout<<max(0LL,P-max(ar[0],ar[1]))<<endl;
    }
}