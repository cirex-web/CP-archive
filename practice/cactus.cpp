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
    int T; cin>>T;
    FR(t,T){
        int N,M; cin>>N>>M;
        vvi g(N); 
        FR(i,M){
            int a,b;cin>>a>>b;a--;b--;
            g[a].push_back(b); g[b].push_back(a);
        }
        ll ans = 1;
        vi nums(N,-1);
        function<void(int,int)> dfs = [&](int a, int par){
            if(par!=-1)nums[a] = nums[par] + 1;
            else nums[a] = 0;
            for(int b:g[a]){
                if(b==par)continue;
                if(nums[b]!=-1){
                    //cycle
//                    cerr<<a<<"->"<<b<<endl;
                    ans*=max(1,nums[a]-nums[b]+1); //prevent going back onto a cycle
                    ans%=1007;
                }else{
                    dfs(b,a);
                }
            }
        };
        dfs(0,-1);
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
        cout<<endl;
    }
    return 0;
}