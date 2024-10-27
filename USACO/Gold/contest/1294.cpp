#include <bits/stdc++.h>
using namespace std;
template<class T> using V = vector<T>;
using ll = long long;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define FORE(i,a,b) for(int i = (a); i<=(b);i++)
#define FRE(i,a) FORE(i,0,a)
#define ROF(i,a,b) for(int i = (a); i>=b;i--)
#define mp make_pair
#define sz(a) ((int)a.size())
int main(){
    int N,T; cin>>N>>T;
    V<V<int>> g(N);
    V<ll> cost(N,LLONG_MAX),costWithEnd(N,LLONG_MAX),time(N),sum(N);
    V<bool> containsEnd(N); //for T=1 case
    V<int> depth(N);
    set<int> deepestLeaves;
    int maxDepth = 0;
    FOR(i,1,N){
        int j,c; cin>>j>>c;j--; //j is parent
        g[j].push_back(i);
        depth[i] = depth[j]+1;
        if(depth[i]>maxDepth){
            maxDepth = depth[i];
            deepestLeaves.clear();
        }
        if(depth[i]==maxDepth)deepestLeaves.insert(i);
        sum[i]=c;
    }

    function<void(int)> dfs = [&](int a){
//        assert(sz(g[a])<=3);

        ll baseCost = 0;
        for(int b:g[a]){
            dfs(b);
            baseCost+=cost[b];
            sum[a]+=sum[b];
            time[a]+=2+time[b];
        }

        if(!sz(g[a])){
            if(deepestLeaves.count(a)) //you can end with da end
                costWithEnd[a] = 0;
            cost[a] = 0;
            return;
        }

        sort(g[a].begin(),g[a].end(),[&](int a, int b){
            return sum[a]*(time[b]+2)>sum[b]*(time[a]+2);
        });

        do{
            ll curCost = baseCost;
            ll passedTime = 0;
            for(int b: g[a]){
                curCost+= (1 + passedTime) * sum[b];
                passedTime+=time[b]+2; //that edge to subtree +2
            }
            cost[a] = min(cost[a], curCost);
        }while(false&&next_permutation(g[a].begin(),g[a].end()));

        //second sort (more restricted cuz we want the end to actually be endable (pick out worst end thing)
        sort(g[a].begin(),g[a].end(),[&](int a, int b){
            if((costWithEnd[a]==LLONG_MAX)!=(costWithEnd[b]==LLONG_MAX)){
                return (costWithEnd[a]!=LLONG_MAX)<(costWithEnd[b]!=LLONG_MAX); //not good stuff first
            }
            return sum[a]*(time[b]+2)>sum[b]*(time[a]+2);
        });
        //sort rest normally
        sort(g[a].begin(),--g[a].end(),[&](int a, int b){
            return sum[a]*(time[b]+2)>sum[b]*(time[a]+2);
        });
//        FR(i,sz(g[a]))cerr<<costWithEnd[g[a][i]]<<endl;
//        cerr<<endl;
        do{
            ll curCost = baseCost;
            ll passedTime = 0;
            for(int b: g[a]){
                curCost+= (1 + passedTime) * sum[b];
                passedTime+=time[b]+2; //that edge to subtree +2
            }

            if(costWithEnd[*g[a].rbegin()]!=LLONG_MAX){
                costWithEnd[a] = min(costWithEnd[a],curCost-cost[*g[a].rbegin()]+costWithEnd[*g[a].rbegin()]);
            }
        }while(false&&next_permutation(g[a].begin(),g[a].end()));
    };
    dfs(0);
    if(!T){
        cout<<time[0]<<" "<<cost[0]<<endl;
    }else{
        cout<<time[0]-maxDepth<<" "<<costWithEnd[0]<<endl;
    }

    return 0;
}