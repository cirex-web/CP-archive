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
        vi cnt(N,-1);
        int timer = 0;
        ll ans = 1;

        function<void(int,int)> dfs = [&](int a, int par){
            cnt[a]=timer++;
            cerr<<a<<endl;
            for(int b:g[a]){
                if(b==par)continue;
                if(cnt[b]!=-1){
                    //cycle!
                    cerr<<a<<"->"<<b<<endl;
                    // if(cnt[a]<cnt[b])continue;
                    ans=ans*(cnt[a]-cnt[b]+1)%1007;
                }else{
                    dfs(b,a);
                    cnt[a] = timer-1; //just resetting
                }
            }
        };
        dfs(1,-1);
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
        if(t<T-1)cout<<endl;
    }
    return 0;
}