#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>

#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define vd vector<double>
#define vvd vector<vd>
#define sz(a) (int(a.size()))

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0)

/*



*/
int main(){
    fast;
    int N,M; cin>>N>>M;
    vector<vector<pair<int,int>>> g(N);
    FR(i,M){
        ll a,b,w;cin>>a>>b>>w;a--;b--;
        g[a].push_back({b,w}); 
    }
    vl dist(N,LLONG_MAX); dist[0] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq; pq.push({dist[0],0});
    while(sz(pq)){
        auto [da,a] = pq.top(); pq.pop();
        if(da>dist[a])continue;
        for(auto [b,w]: g[a]){
            if(dist[a]+w<dist[b]){
                pq.push({dist[b]=dist[a]+w,b});
            }
        }
    }
    FR(i,N){
        cout<<dist[i]<<" \n"[i==N-1];
    }
    return 0;
}