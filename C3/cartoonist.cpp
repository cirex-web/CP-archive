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
#define all(a) a.begin(),a.end()
#define vl vector<ll>
#define vvl vector<vl>
using ll = long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N; vi ar(N);
        FR(i,N)cin>>ar[i];FR(i,N)cin>>ar[i];
        sort(all(ar)); 
        int a = 0,b = 0;
        for(int num: ar){
            if(a<b){
                a+=num;
            }else{
                b+=num;
            }
        }
        cout<<max(a,b)<<endl;
    }
    return 0;
}