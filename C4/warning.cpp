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

3
4
1 2 3 5
1 4
2 4
4 3 
5
1 4 4 4 1
1 2
2 3
3 4
4 5 
3
1 2 2
2 1
1 3


*/
struct nodeData{
    ll NOT_HAS, HAS;
};

int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vvi g(N);vl cost(N); FR(i,N)cin>>cost[i];
        
        FR(i,N-1){
            int a,b; cin>>a>>b;a--;b--;
            g[a].push_back(b); g[b].push_back(a);
        }
        function<nodeData(int,int)> dfs = [&](int i, int par){
            nodeData cur{0,cost[i]};
            vector<nodeData> allData;

            for(int j: g[i]){
                if(par==j)continue;
                auto childData = dfs(j,i);
                cur.HAS+=min(childData.HAS,childData.NOT_HAS);
                cur.NOT_HAS+=childData.HAS;
            }
            
            //the cheapest way was to not take any child HAS (ok well now you have to)

            return cur;
        };
        auto data = dfs(0,-1);
        cout<<min(data.NOT_HAS,data.HAS)<<endl;
    }
    return 0;
}