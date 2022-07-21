#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(a) (int(a.size()))

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    int T; cin>>T;
    FR(t,T){
        int N,M,R; cin>>N>>M>>R;
        int sx,sy,ex,ey; cin>>sx>>sy>>ex>>ey;
        vvi g(N,vi(M,0));
        FR(r,R){
            int x,y;cin>>x>>y;
            g[x][y] = 1;
        }
        vvi dist(N,vi(M,INT_MAX)),vis(N,vi(M,0)); 
        dist[sx][sy] = 0; vis[sx][sy] = 1;
        queue<pair<int,int>> q; q.push({sx,sy});
        while(sz(q)){
            auto [x1,y1] = q.front(); q.pop();
            // cerr<<"-> "<<x1<<" "<<y1<<endl;
            FR(i,4){
                int x2 = x1+dx[i], y2 = y1+dy[i];
                if(x2>=0&&x2<N&&y2>=0&&y2<M&&!vis[x2][y2]&&!g[x2][y2]){
                    dist[x2][y2] = dist[x1][y1]+1;
                    vis[x2][y2] = 1;
                    q.push({x2,y2});
                }
            }
        }
        cout<<(vis[ex][ey]?to_string(dist[ex][ey]):":(")<<endl;
    }

    return 0;
}