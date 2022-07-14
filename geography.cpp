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

struct DSU{
    vi par;
    DSU(int N){
        par.resize(N,-1);
        
    }
    int parent(int a){
        // cerr<<a<<endl;
        return par[a]<0?a:(par[a]=parent(par[a]));
    }
    void merge(int a, int b){
        a = parent(a); b = parent(b);
        if(a==b)return;
        if(-par[a]<-par[b])swap(a,b);
        par[a] += par[b]; //add the size
        par[b] = a;
    }
};

int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N,M; cin>>N>>M;
        DSU g(N);
        FR(i,M){
            int a,b;cin>>a>>b;a--;b--;
            g.merge(a,b);
        }
        set<int> seen;
        ll ans = 0;
        FR(i,N){
            int par = g.parent(i);
            if(!seen.count(par)){
                ll size = -g.par[par];
                ans+=(size)*(size-1)/2;
                seen.insert(par);
            }
        }
        cout<<ans<<endl;

        
    }
}