#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N,K; cin>>N>>K;
        vl pre(N-K+1);
        vl ar(N);FR(i,N)cin>>ar[i];
        FR(i,K)pre[0]+=ar[i];
        FOR(i,1,N-K+1){
            pre[i] = pre[i-1]-ar[i-1]+ar[i+K-1];
        }
        vi segs(N-K+1); FR(i,sz(segs))segs[i] = i;
        sort(all(segs),[&](int a, int b){
            if(pre[a]!=pre[b])return pre[a]>pre[b];
            return a<b;
        });
        FR(i,sz(segs)){
            cout<<segs[i]+1<<" \n"[i==sz(segs)-1];
        }
        
    }
}