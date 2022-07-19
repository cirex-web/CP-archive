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
struct num{
    int val,i;
};
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N,K; cin>>N>>K;
        string str;cin>>str;
 
        auto cmp = [&](int i, int j){
            if(str[i]!=str[j])return str[i]>str[j];
            return i<j;
        };
        set<int,decltype(cmp)> s(cmp);
        FR(i,N-K)s.insert(i);
        int j = 0;
        FR(i,K){
            s.insert(N-K+i);
            int end = *s.begin();
            cout<<str[end];
            for(;j<=end;j++){
                s.erase(s.find(j));
            }
            
        }
        cout<<endl;
        
    }
    return 0;
}