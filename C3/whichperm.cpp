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

        int N; cin>>N;
        vi difs(N-1); 
        FR(i,N-1)cin>>difs[i];
        set<int> s; vb flip(N-1),ans;
        function<bool(int,int)> dfs = [&](int n, int i){
            // cerr<<n<<" "<<i<<endl;
            if(n>=N||n<0)return false;
            if(s.count(n))return false;
            if(i==N-1){
                ans=flip;
                return true;
            }
            s.insert(n);
            
            flip[i] = 1;
            bool res = dfs(n-difs[i],i+1);
            flip[i] = 0;
            res = res || dfs(n+difs[i],i+1);
            s.erase(s.find(n));
            return res;
        };
        FR(start,N){
            bool ok = dfs(start,0);
            assert(sz(s)==0);
            if(sz(ans)){

                cout<<start;
                FR(i,N-1){
                    if(ans[i])difs[i]*=-1;
                    start+=difs[i];
                    cout<<" "<<start;
                }
                cout<<endl;
                goto done;
            }
        }
        // do{
        //     FOR(i,1,N){
        //         if(abs(ar[i]-ar[i-1])!=difs[i-1])goto nxt;
        //     }
        //     FR(i,N){
        //         cout<<ar[i]<<" \n"[i==N-1];
        //     }
        //     goto done;
        //     nxt:;
        // }while(next_permutation(all(ar)));
        // cout<<"impossible"<<endl;
        cout<<"impossible"<<endl;
        done:;
    }
    // int T; cin>>T;
    // FR(t,T){
    //     int N; cin>>N;
    //     vvi dp(N,vi(N))
    // }
    return 0;
}