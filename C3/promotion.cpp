#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FORE(i,a,b) for(int i = (a); i<=(b); i++)

#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FR(i,a+1)

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vb vector<bool>
#define vvb vector<vb>
#define sz(a) (int(a.size()))
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    FR(t,T){
        int N,Q; cin>>N>>Q;
        vi ar(N); FR(i,N)cin>>ar[i];
        vi pre(N+1,0); FR(i,N)pre[i+1] = pre[i]+ar[i];
        FR(q,Q){
            int W,low; cin>>W>>low;
            int cnt = 0;
            FR(i,N-W){
                cnt+=double(pre[i+W]-pre[i])/W>=low;
                // cerr<<pre[i+W]-pre[i]<<endl;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
//Note that the student will not be offered a promotion after the last contest