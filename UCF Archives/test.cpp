
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i<(b);i++)
#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FR(i,a+1)

#define fast ios::sync_with_stdio(0);cin.tie(0)
using vi = vector<int>;
struct DSU{
    vi ar;
    DSU(int N){
        ar.resize(N);
        FR(i,N){
            ar[i] = i;
        }
    }
    int par(int a){
        return ar[a]==a?a:ar[a]=par(ar[a]);
    }
    void merge(int a, int b){
        a = par(a);
        b = par(b);
        ar[a] = b;
    }
};
int main() {
    fast;
    DSU d(4);
    d.merge(2,3);
    FR(i,4){
        cerr<<d.par(i)<<endl;
    }
    cout<<"h";

    
    return 0;
}
