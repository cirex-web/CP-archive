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
#define sz(a) (int(a.size()))
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    vector<double> ar(1000005);
    double prefix = 0;
    FOR(i,1,sz(ar)){
        ar[i] = (i+1+prefix)/i;
        prefix+=ar[i];
    }
    FR(t,T){
        int N; cin>>N;
        cout<<setprecision(7)<<fixed<<ar[N]<<endl;
    }
    return 0;
}