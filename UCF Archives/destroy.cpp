#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
using vi = vector<int>;
using ll = long long;
struct DSU{
    vi par, sz;
    DSU(int N){
        par.resize(N); sz.resize(N);
        FR(i,N){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int p(int a){
        // cerr<<"f"<<a<<endl;
        return par[a]==a?a:(par[a]=p(par[a]));
    }
    ll merge(int a, int b){
        // cerr<<a<<" "<<b<<" "<<sz(par)<<endl;
        a = p(a);
        b = p(b);
        if(sz[b]>sz[a])swap(a,b);
        ll res = 0;
        if(a!=b){
            res-=sz[a]*sz[a];
            res-=sz[b]*sz[b];
            res+=(sz[a]+sz[b])*(sz[a]+sz[b]);
            par[b] = a;
            sz[a]+=sz[b];
        }
        return res;
    }
};
int main(){
    int T; cin>>T;
    FR(t,T){
        int N,M,D;cin>>N>>M>>D;
        vector<pair<int,int>> edges,rem;
        FR(m,M){
            int u,v;cin>>u>>v;u--;v--;
            edges.push_back({u,v});
        }
        FR(i,D){
            int n; cin>>n;n--;
            rem.push_back(edges[n]);
            edges[n] = {-1,-1};

        }
        ll cur = N;
        DSU d(N);
        FR(i,M){
            //gen graph
            if(edges[i].first==-1)continue;
            cur+=d.merge(edges[i].first,edges[i].second);
        }
        vector<ll> ans = {cur};
        reverse(rem.begin(),rem.end());
        FR(i,sz(rem)){
            // cerr<<rem[i].first<<">"<<endl;
            ans.push_back(ans.back()+d.merge(rem[i].first,rem[i].second));
        }
        ROF(i,sz(ans)-1,0){
            cout<<ans[i]<<endl;
        }
    }
    
    return 0;
}