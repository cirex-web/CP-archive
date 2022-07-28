#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;
struct knight{
    int death,years,q;
};
struct ev{
    int t,i;
    bool add;
};
int main(){
    while(1){
        int N; cin>>N;
        if(!N)break;
        int M,P; cin>>M>>P;
        vvi g(N);
        int cnt = 0;
        map<char,int> ctoi;
        FR(p,P){
            string path;cin>>path;
            char a = path[0], b = path[1];
            if(!ctoi.count(a))ctoi[a]=cnt++;
            if(!ctoi.count(b))ctoi[b]=cnt++;
            g[ctoi[a]].pb(g[ctoi[b]])
        }
    }
   
    
    return 0;
}